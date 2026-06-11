#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
long long mymin(long long x,long long y)
{
	if(x==-1)
		return y;
	return min(x,y);
}
long long x[202020];
long long sum[202020];
int h[202020];
int main()
{
	int n;
	long long xx;
	long long ans=-1,now=0;
	scanf("%d%lld",&n,&xx);
	sum[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
		sum[i]=sum[i-1]+x[i];
	}
	h[1]=5;
	h[2]=5;
	for(int i=3;i<=n;i++)
		h[i]=h[i-1]+2;
	for(int i=1;i<=n;i++)
	{
		now=(long long)xx*(i+n);
		for(int j=n,cnt=1;j>=1;j-=i,cnt++)
		{
			now+=(sum[j]-sum[max(j-i,0)])*h[cnt];
			if(now>ans&&ans!=-1)
				break;
		}
		ans=mymin(ans,now);
	}
	printf("%lld",ans);
	return 0;
}