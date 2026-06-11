#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define int long long
using namespace std;
int k,a[1000];
__int128 s(__int128 x)
{
	__int128 ans=0;
	while (x) ans+=x%10,x/=10;
	return ans;
}
signed main()
{
	// __int128 wh;
	// wh=109999999999999;
	// int k=s(wh);
	// printf("%lld\n",k);
	// if (wh<1e12*s(wh)) printf("YES\n");
	// else printf("NO\n");
	scanf("%lld",&k);
	a[0]=9;a[1]=99;
	for (int i=2;i<=10;i++)
	{
		a[i]=i-1;
		for (int j=1;j<=i+1;j++) a[i]=a[i]*10+9;
	}
	a[11]=9999999999999;
	for (int i=12;i<=16;i++)
	{
		a[i]=i-2;
		for (int j=1;j<=i+1;j++) a[i]=a[i]*10+9;
	}
	// for (int i=1;i<=16;i++) printf("%lld\n",a[i]);
	// printf("\n");
	int now=1,cnt=0,x=0;
	for (int i=1;i<=k;i++)
	{
		x+=now;
		printf("%lld\n",x);
		if (x==a[cnt])
		{
			cnt++;
			now*=10;
		}
	}
}