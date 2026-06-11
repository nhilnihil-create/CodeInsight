#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define LL long long
using namespace std;
const LL inf=(LL)9e18;
LL a[200010],n,x,ans=inf;
int main()
{
	scanf("%lld %lld",&n,&x);
	for(LL i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]+=a[i-1];
	for(LL k=1;k<=n;k++)
	{
		LL cost=3,sum=0;
		for(LL i=n;i>=1;i-=k)
		{
			sum+=(a[i]-a[max(0LL,i-k)])*max(5LL,cost),cost+=2;
			if(sum>ans) break;
		}
		ans=min(ans,sum+(k+n)*x);
	}
	printf("%lld",ans);
}