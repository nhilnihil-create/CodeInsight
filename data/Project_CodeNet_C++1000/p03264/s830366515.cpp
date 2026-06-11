#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int m;
	cin>>m;
	if(m&1)
	{
		m>>=1;
		cout<<m*(m+1);
	}
	else
	{
		m>>=1;
		cout<<m*m;
	}
	return 0;
} 