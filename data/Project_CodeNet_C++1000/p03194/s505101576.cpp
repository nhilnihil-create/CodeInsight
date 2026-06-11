#include<bits/stdc++.h>
using namespace std;
long long qpow(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
			ans=ans*a;
		a=a*a;
		b=b/2;
	}
	return ans;
}
int main()
{
	long long n,p;
	cin>>n>>p;
	long long m=sqrt(p);
	if(n==1 || p==1)
		cout<<p<<endl;
	else
	{
		long long ans=1;
		for(long long j=2;j<=m;j++)
		{
			while(p%(long long)pow(j,n)==0)
			{
				p=p/(long long)pow(j,n);
				ans=ans*j;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 