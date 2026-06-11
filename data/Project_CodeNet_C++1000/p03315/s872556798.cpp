#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main()
{
	char a[4];
	int sum=0;
	for(int i=0;i<4;i++)
	{
		cin>>a[i];
		if(a[i]=='+')
		{
			sum++;
		}
		else
		{
			sum--;
		}
	}
	cout<<sum;
	return 0;
 } 