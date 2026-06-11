#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
char a[4];
for(int i=0;i<4;i++)
{
cin>>a[i];
}
if(a[0]==a[1]&&a[0]==a[2]&&a[0]==a[3])
cout<<"Yes";
else if(a[0]==a[1]&&a[0]==a[2])
cout<<"Yes";
else if(a[1]==a[2]&&a[1]==a[3])
cout<<"Yes";

else
cout<<"No";
return 0;  
}