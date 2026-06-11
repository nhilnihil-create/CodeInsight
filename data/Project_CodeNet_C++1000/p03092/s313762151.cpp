#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 2333333333333333333LL

ll f[5010][5010],a,b;
int num[5010],p[5010],n;

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

int main()
{
	n=rd();a=rd();b=rd();
	for (int i=1;i<=n;i++) num[i]=rd(),p[num[i]]=i;
	for (int i=1;i<=n;i++)
	{
		if (i==p[1]) f[1][i]=0;
		else if (i<p[1]) f[1][i]=b;
		else f[1][i]=a;
	}
	for (int i=2;i<=n;i++)
	{
		for (int j=1;j<=n;j++) f[i][j]=inf;
		ll mn=inf;
		for (int j=1;j<=n;j++)
		{
			mn=min(mn,f[i-1][j]);
			if (j<p[i]) f[i][j]=min(f[i][j],mn+b);
			else if (j==p[i]) f[i][j]=min(f[i][j],mn);
			else f[i][j]=min(f[i][j],mn+a);
		}
	}
	ll ans=inf;
	for (int i=1;i<=n;i++) ans=min(ans,f[n][i]);
	printf("%lld\n",ans);
	return 0;
}