#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

int n,m,x,y,depth[500010],ans=0;
vector <int> g[500010];
bool vis[500010];

int dfs(int pos,int no,int d)
{
	vis[pos]=true;
	depth[pos]=d;
	int low=d;
	rep(i,g[pos].size())
	{
		if(g[pos][i]==no) continue;
		if(depth[g[pos][i]]<d) low=min(low,depth[g[pos][i]]);
		else if(!vis[g[pos][i]])
		{
			int tmp=dfs(g[pos][i],pos,d+1);
			low=min(low,tmp);
			if(tmp>d) ans++; 
		}
	}
	return low;
}

int main()
{
	cin>>n>>m;
	rep(i,m)
	{
		scanf("%d%d",&x,&y);
		g[x].pb(y);
		g[y].pb(x);
	}
	rep(i,500005) depth[i]=1e9; 
	dfs(1,0,0);
	cout<<ans<<endl;
	return 0;
}