#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int N=500010;
int op,n,now;
LL m,v,ans,tot,sum[N];
int main()
{
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&v);
		sum[i]+=sum[i-1]+v;
	}
	ans=0x7fffffffffffffff;
	for(int i=1;i<=n;i++)
	{
		v=1;now=n-i*2;tot=(sum[n]-sum[max(n-i*2,0)])*5+m*(n+i);
		while(now>0)
		{
			tot+=(sum[now]-sum[max(0,now-i)])*(2*v+5);
			if(tot<0){tot=0x7fffffffffffffff;break;}now-=i;v++;
		}
		ans=min(ans,tot);
	}
	printf("%lld\n",ans);
	return 0;
}