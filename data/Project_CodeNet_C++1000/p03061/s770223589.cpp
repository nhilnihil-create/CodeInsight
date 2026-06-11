#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long e[100005],f[100005],h[100005];
long long gcd(long long a,long long b)
{
	return b==0?a:gcd(b,a%b);
}
long long max(long long a,long long b)
{
	return a>b?a:b;
}
int main()
{
	long long ans=0;
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&e[i]);
		if(i==0)
			f[i] = e[i];
		else
			f[i] = gcd(f[i-1],e[i]);
	}
	for(i=n-1;i>=0;i--)
	{
		if(i==n-1)
			h[i] = e[i];
		else
			h[i] = gcd(h[i+1],e[i]);
	}
	for(i=0;i<n;i++)
	{
		if(i==0)
			ans = max(ans,h[i+1]);
		else if (i==n-1)
			ans = max(ans,f[i-1]);
		else
			ans = max(ans,gcd(f[i-1],h[i+1]));
	}
	printf("%lld",ans);
	return 0;
}