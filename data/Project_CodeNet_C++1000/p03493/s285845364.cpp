#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
int main() 
{ 
int n;
cin>>n;
int r,sum=0,c=0;
int temp=n;
while(temp!=0)
{
	r=temp%10;
	if(r==1)
{
	c++;
	
}
	
	temp=temp/10;
}


cout<<c;



return 0;  
}