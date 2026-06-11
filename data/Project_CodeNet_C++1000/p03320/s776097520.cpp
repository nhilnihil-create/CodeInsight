#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int S(long long x)
{
	int r=0;
	while(x)
		r+=x%10,x/=10;
	return r;
}
int main()
{
	long long k,p=2,q=1;
	scanf("%d",&k);
	while(k)
	{
		long long n=p*q-1,m=ceil((double)p/10.0)*q*10-1;
		if(n*S(m)>m*S(n))
			p=ceil((double)p/10.0),q*=10;
		else
		{
			printf("%lld\n",n);
			k--,p++;
		}
	}
	return 0;
}