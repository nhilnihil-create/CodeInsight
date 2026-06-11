#include<iostream>
#include<cstdio>
using namespace std;
int n;
int main()
{
	int i,j,u,v;
	cin>>n;
	i=n/100;
	j=(n/10)%10;
	u=n%10;
	if(i>j)
	{
		cout<<i<<i<<i<<endl;
	}
	else if(i<j)
	{
		cout<<i+1<<i+1<<i+1<<endl;
	}
	else
	{
		if(u<=j)
		{
			cout<<i<<i<<i<<endl;
		}
		else
		{
			cout<<i+1<<i+1<<i+1<<endl;
		}
	}
	return 0;
} 