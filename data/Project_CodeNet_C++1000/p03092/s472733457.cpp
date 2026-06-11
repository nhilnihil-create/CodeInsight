#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int pos[5010];
long long f[2][5010];
int n;
int a,b;
int main()
{
	scanf("%d %d %d",&n,&a,&b);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		pos[x]=i;
	}
	for(int i=1;i<=n;i++)
		if(i<pos[1])f[1][i]=b;
		else if(i>pos[1])f[1][i]=a;
		else f[1][i]=0;
	for(int i=2;i<=n;i++)
	{
		int now=i&1;
		int lst=now^1;
		for(int j=1;j<=n;j++)
			if(j<pos[i])
				f[now][j]=f[lst][j]+b;
			else if(j==pos[i])
			{
				f[now][j]=1e18;
				for(int k=1;k<=j;k++)
					f[now][j]=min(f[now][j],f[lst][k]);
			}
			else f[now][j]=f[lst][j]+a;
	}
	long long ans=1e18;
	for(int i=1;i<=n;i++)
		ans=min(ans,f[n&1][i]);
	printf("%lld\n",ans);
	return 0;
}