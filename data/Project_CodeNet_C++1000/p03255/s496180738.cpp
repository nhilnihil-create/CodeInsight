#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const LL N=200005;
LL n,X; 
LL a[N];
LL ans;
LL sum[N];
int main()
{
	scanf("%lld%lld",&n,&X);
	ans=0;
	for (LL u=1;u<=n;u++) 
	{
		scanf("%lld",&a[u]);
		sum[u]=sum[u-1]+a[u];
		ans=ans+a[u]+X+a[u]*4;
	}
	//printf("%lld\n",ans);
	for (LL u=n-1;u>=1;u--)
	{
		LL j;LL cnt=1;
		LL tot=X*u;
		for (LL i=n;i>=1;i=j-1)
		{
			j=max(1LL,i-u+1);//这一段都是cnt
			if (cnt==1) tot=tot+(sum[i]-sum[j-1])*(1+4);
			else tot=tot+(sum[i]-sum[j-1])*(2*cnt+1);
			cnt++;
			if (tot>=ans) break;
		}
		ans=min(ans,tot);
	}
	printf("%lld\n",ans+n*X);
	return 0;
}