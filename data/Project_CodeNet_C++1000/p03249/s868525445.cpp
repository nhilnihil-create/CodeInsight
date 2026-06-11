#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#define ll long long
using namespace std;
map<ll,int>mp;
struct DIAN
{
	int bh;
	long long d;
}ak[100010];
bool cmp(const DIAN&xx,const DIAN&yy)
{
	return xx.d>yy.d;
}
vector<int>G[100010];
ll sz[100010];
ll dep[100010];
int n;
void dfs(int x,int fx)
{
	int i;
	dep[x]=dep[fx]+1;
	for(i=0;i<G[x].size();i++)
	{
		if(G[x][i]==fx)continue;
		dfs(G[x][i],x);
	}
}
void dfss(int x,int fx)
{
	int i;
	for(i=0;i<G[x].size();i++)
	{
		if(G[x][i]==fx)continue;
		printf("%d %d\n",x,G[x][i]);
		dfss(G[x][i],x);
	}
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&ak[i].d);
		ak[i].bh=i;
		mp[ak[i].d]=i;
	}
	ll bli=ak[1].d;
	sort(ak+1,ak+n+1,cmp);
	for(i=1;i<n;i++)
	{
		sz[ak[i].bh]++;
		if(n-2*sz[ak[i].bh]<=0)
		{
			printf("-1\n");
			return 0;
		}
		ll qwq=ak[i].d-1ll*(n-2*sz[ak[i].bh]);
		if(mp.find(qwq)==mp.end())
		{
			printf("-1\n");
			return 0;
		}
		G[ak[i].bh].push_back(mp[qwq]);
		G[mp[qwq]].push_back(ak[i].bh);
		sz[mp[qwq]]+=sz[ak[i].bh];
	}
	dfs(1,0);
	ll alk=0;
	for(i=1;i<=n;i++)
		alk+=(dep[i]-1ll);
	if(alk!=bli)
	{
		printf("-1\n");
		return 0;
	}
	dfss(1,0);
	return 0;
}