#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	long long s=0;
	for(int i=1;i<=n;i++)
	{
		long long a;
		cin>>a;
		while(a%2==0)
		{
			a=a/2;
			s++;
		}
	}
	cout<<s;
 } 