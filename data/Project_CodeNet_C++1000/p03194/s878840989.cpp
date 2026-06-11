#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<cstring>
#include<cmath>
#define int unsigned long long
using namespace std;
int n,p,x;
int cnt;
int ans=1;
int pr[10000010],c[10000010];
int pp(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=res*a;
		a=a*a;
		b>>=1;
	}
	return res;
}
signed main()
{
	scanf("%lld%lld",&n,&p);
	if(n==1)
	{
		cout<<p;
		return 0;
	}
	int ss;
	ss=sqrt(p);
	for(int i=2;i<=ss;i++)
	{
		if(p%i==0)
		{
			cnt++;
			pr[cnt]=i;
			c[i]=0;
			while(p%i==0)
			{
				p=p/i;
				c[i]++;
			}
		}
		if(p==1)
			break;
	}
	int s;
	for(int i=1;i<=cnt;i++)
	{
		if(c[pr[i]]>=n)
		{
			s=c[pr[i]]/n;
			ans=ans*pp(pr[i],s);
		}
	}
	cout<<ans;
}