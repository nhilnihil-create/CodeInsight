#include<iostream>
 using namespace std ;
 int main()
{
short int c=0;
char s[3];

cin>>s;

if(s[0]=='1') ++c;

if(s[1]=='1') ++c;

if(s[2]=='1') ++c;

 cout<<c;


}