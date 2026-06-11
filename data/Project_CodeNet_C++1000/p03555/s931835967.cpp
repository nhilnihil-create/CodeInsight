#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
char a[3],b[3];
for(int i=0;i<3;i++)
{
cin>>a[i];
}
for( int i=0;i<3;i++)
{
cin>>b[i];
}
if(a[0]==b[2]&&a[1]==b[1]&&a[2]==b[0])
cout<<"YES";
else
cout<<"NO";
return 0;  
}