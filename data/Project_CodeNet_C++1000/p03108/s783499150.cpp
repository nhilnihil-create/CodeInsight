#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int par[maxn],sz[maxn],x[maxn],y[maxn],n,m;
long long now,ans[maxn];
int find(int x)
{
	if(par[x]==x)return x;
	else return par[x]=find(par[x]);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		par[i]=i;
		sz[i]=1;
	}
	for(int i=1;i<=m;i++)
	scanf("%d %d",&x[i],&y[i]);
	now=(long long)n*(n-1)/2;
	for(int i=m;i>=1;i--)
	{
		ans[i]=now;
		int X=x[i],Y=y[i];
		X=find(X);Y=find(Y);
		if(X==Y)continue;
		now-=sz[X]*sz[Y];
		par[X]=Y;
		sz[Y]+=sz[X];
	}
	for(int i=1;i<=m;i++)
	printf("%lld\n",ans[i]);
	return 0;
}
