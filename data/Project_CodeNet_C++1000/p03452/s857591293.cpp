#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX_N 100005
#define int long long

using namespace std;

int n,m;
int par[MAX_N];
int dis[MAX_N];

int find(int x)
{
	if(par[x]==x) return x;
	int p=par[x];
	par[x]=find(par[x]),dis[x]+=dis[p];
	return par[x];
}

bool unite(int x,int y,int z)
{
	int px=find(x),py=find(y);
	if(px==py) return dis[x]-dis[y]==z;
	dis[px]=-dis[x]+z+dis[y],par[px]=py;
	return true;
}

signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) par[i]=i;
	int l,r,d;
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&l,&r,&d);
		if(!unite(l,r,d))
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}
