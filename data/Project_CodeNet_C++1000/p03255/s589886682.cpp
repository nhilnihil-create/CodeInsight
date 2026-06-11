#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

typedef unsigned long long LL;

const int N=200005;

int n;
LL a[N],val[N],m;

int main()
{
	scanf("%d%llu",&n,&m);
	for (int i=1;i<=n;i++) scanf("%llu",&a[i]);
	for (int i=1;i<=n;i++) val[i]=val[i-1]+a[i];
	LL ans=0;
	for (int i=1;i<=n;i++) ans+=a[i]+(LL)a[i]*4+m;
	for (int i=1;i<=n;i++)
	{
		LL w=(val[n]-val[n-i])*2;
		for (int j=n,s=0;j>0;j-=i,s++)
		{
			w+=(LL)(val[j]-val[std::max(0,j-i)])*(s*2+3);
		}
		ans=std::min(ans,w+(LL)m*i);
	} 
	printf("%llu\n",ans+(LL)m*n);
	return 0;
}