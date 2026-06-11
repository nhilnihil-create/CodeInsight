#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int i,a,b,s=0;
	cin>>a>>b;
	if(a<=b)
	{
		for(i=1;i<=a;i++)
			s++;
	}
	else
	{
		for(i=1;i<=a-1;i++)
			s++;
	}
	cout<<s;
	
}