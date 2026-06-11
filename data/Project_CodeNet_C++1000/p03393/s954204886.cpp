#include<iostream>
#include<set>
#include<vector>
using namespace std;
bool prime(int x)
{
	for(int i=2;i*i<=x;i++)
    {
		if(x%i==0)
		   return false;
	}
	return true;
}
int main()
{
     string str;
     cin>>str;
     set<char> s;
     for(char x='a';x<='z';x++)
       s.insert(x);
     if(str.size()<26)
     {
		 for(char x:str)
		 {
			 auto it=s.find(x);
			 s.erase(x);
		 }
		 cout<<str;
		 cout<<*(s.begin())<<endl;
	 }
	 else
	 {
		 if(str=="zyxwvutsrqponmlkjihgfedcba")
		    cout<<-1<<endl;
		 else
		 {
			 int j,l=str.size();
			 for(j=l-1;j>=0;j--)
			 {
				 set<char> temp;
				 for(int i=j+1;i<l;i++)
				 {
					 if(str[i]>str[j])
					   temp.insert(str[i]);
				 }
				 if(temp.size()!=0)
				 {
					 for(int ptr=0;ptr<j;ptr++)
					 {
						 cout<<str[ptr];
					 }
					 cout<<*(temp.begin())<<endl;
					 exit(0);
				 }
			 }
		 }
	 }
}
