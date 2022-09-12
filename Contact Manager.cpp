#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
class Contact{
	int  id;
	char name[20];
	char email[50];
	char mobile[108];
	char city[20];
	
	public :
	Contact()
	{
		
	}
	Contact (int cid,const char* cname,const char* cemail,const char* cmobile,const char* ccity)
	{
		id = cid;
		strcpy(mobile, cmobile);
		strcpy(name, cname);
		strcpy(email, cemail);
		strcpy(city, ccity);		
	}
    void disp()
    {
		cout<<"Id : "<<id<<endl;
		cout<<"Name : "<<name<<endl;
		cout<<"Email : "<<email<<endl;
		cout<<"Mobile : "<<mobile<<endl;
		cout<<"City : "<<city<<endl;
		cout<<"--------------------------------------------------------------------"<<endl;
    }
    
	friend void search(int id);
	friend void deleteRecord(int id);
};

void addContact(Contact c)
{
	ofstream fout("Contacts.dat",ios::app);
	fout.write((char*)&c,sizeof(c));
	fout.close();
	cout<<"Contact Added Successfully..!"<<endl;
	
}
void dispAll()
{
	Contact temp;
	ifstream fin("Contacts.dat");
	while(1)
	{
		fin.read((char*)&temp,sizeof(temp));
		if(fin.eof())
		{
			break;
		}
		else
		{
			temp.disp();
			
		}
	}
}
void search(int id )
{
	ifstream fin("Contacts.dat");
 	Contact temp;
    while(1)
	{
		fin.read((char*)&temp,sizeof(temp));
		if(fin.eof()==true)
		{
			break;
		}
		if(temp.id==id)
		{
			cout<<"Record Found : "<<endl;
			temp.disp();
		}
	}
}
void deleteRecord(int id)
{
	ifstream fin("Contacts.dat");
	ofstream fout("temp.dat");
	Contact obj;
	while(1)
	{
		fin.read((char*)&obj,sizeof(obj));
		if(fin.eof())
		{
			break;
		}
		else
		{
			if(obj.id!=id)
			{
				fout.write((char*)&obj,sizeof(obj));
			}
		}
	}
	fin.close();
	fout.close();
	cout<<"Contact Deleted Successfully..!"<<endl;
	remove("Contacts.dat");
	rename("temp.dat","Contacts.dat");
}
int main(int argc,char** argv)
{ 

   	Contact c1(1,"sam","sam@gmail.com","347348758222","dhule");
	c1.disp();
	int ch;
	while(1)
	{
	cout<<"Select choice : "<<endl;
	cout<<"1.Add Contact 2.Display All 3.Search Contact 4.Delete Contact 5.Exit "<<endl;
	cin>>ch;
	
       
       switch(ch)
	   {
		case 1:
		{
				int id;
				char name[30],email[50],mobile[10],city[20];
				cout<<"Enter Id :";
				cin>>id;
				cout<<"Enter Name :";
				cin>>name;
				cout<<"Enter your email :";
				cin>>email;
				cout<<"Enter your mobile :";
				cin>>mobile;
				cout<<"Enter your city :";
				cin>>city;
				Contact c1(id,name,email,mobile,city);
	            addContact(c1);
		}
		break;
		case 2:
	    {
		   dispAll();
		   	
		}	
		break;
		case 3:
		{   
		    int id;
		    cout<<"Enter id to be searched :";
		    cin>>id;
			search(id);
		}
		break;
		case 4:
		{
			int id;
		    cout<<"Enter id to be deleted :";
		    cin>>id;
			deleteRecord(id);
		}	
		break;
		case 5:
		{
			exit(0);
			cout<<"Thank you for using our services ...!";
		}	
    	}
	
	}
    

  return 0;
	
}
