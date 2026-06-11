#include<iostream>
 using namespace std ;
 int main()
{
short int c=0,price;
char s[3];

cin>>s;

if(s[0]=='o') ++c;
if(s[1]=='o') ++c;
if(s[2]=='o') ++c;

price=700+c*100;

cout<<price;

}