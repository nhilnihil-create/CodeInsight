#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 200100

ll n,w;
__int128 res,ans;
ll d[N],sum[N],a[N];

int main()
{
	scanf("%lld%lld",&n,&w);
	for (int i=1;i<=n;i++) scanf("%lld",&d[i]),sum[i]=sum[i-1]+d[i];
	a[1]=a[2]=5;
	for (int i=3;i<=n;i++) a[i]=a[i-1]+2;
	for (int i=1;i<=n;i++)
	{
		res=0;
		int now=n,j=1;
		while (now>0)
		{
			res+=(sum[now]-sum[max(now-i,0)])*a[j];
			now-=i; j++;
		}
		if (i==1) ans=i*w+res; else
		ans=min(ans,i*w+res);
	}
	printf("%lld\n",ans+n*w);
	return 0;
}