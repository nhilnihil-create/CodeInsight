#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+5;
const ll mod=1e9+7;
vector<int> nei[maxn];
ll num[5][maxn];
void dfs(int root,int fa)
{
	num[0][root]=num[1][root]=1;
	for(int i=0;i<(int)nei[root].size();i++)
	{
		int next=nei[root][i];
		if(next==fa) continue;
		dfs(next,root);
		(num[0][root]*=(num[0][next]+num[1][next]))%=mod;
		(num[1][root]*=num[0][next])%=mod;
	}
	return;
}
void fl()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
int main()
{
//    fl();
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		nei[u].push_back(v);
		nei[v].push_back(u);
	}
	dfs(1,0);
	ll ans=(num[0][1]+num[1][1])%mod;
	printf("%lld\n",ans);
	return 0;
}
