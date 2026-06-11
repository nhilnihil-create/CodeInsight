#include<iostream>
#include<math.h>
 using namespace std ;
 int main()
{
short int a,b,c,d;

cin>>a;
cin>>b;
cin>>c;
cin>>d;
if((abs(c-a))<=d) cout<< "Yes";
else
 if((abs(c-b)<=d)&& ( abs(b-a)<=d) ) cout<< "Yes";
else
cout<< "No";




}