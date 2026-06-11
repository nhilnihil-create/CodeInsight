#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	long long a,b,res;
	

	cin>>b>> a;
	if(a==b){
		cout << a;
		return 0;
	}
	
	if(b>1)
	{
	b=b-1;
	if(a%4==1)   a=1;
	else if(a%4==2)  a=a+1;
	else  if(a%4==3)  a=0;
	else a=a;           
	if(b%4==1)   b=1;
	else if(b%4==2)  b=b+1;
	else  if(b%4==3)  b=0;
	else b=b;   
	res=a^b;
    }    
	else if(b==1)
	{
		if(a%4==1)   a=1;
		else if(a%4==2)  a=a+1;
		else  if(a%4==3)  a=0;
		else a=a;           
		res= a; 
	}
	
	cout << res;
	
}
