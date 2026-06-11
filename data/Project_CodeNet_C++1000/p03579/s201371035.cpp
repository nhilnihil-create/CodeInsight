#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;
const int N = 1e5+4;
vector <int> adj[N];
bool visit[N];
bool color[N];
bool ck;
int n,m;
void dfs(int s)
{
	for(auto u : adj[s])
	{
		if(visit[u] == false)
		{
			color[u] = 1-color[s];
			visit[u] = true;
			dfs(u);
		}

		else
		{
			if(color[u] != 1-color[s])
				ck = true;
		}
	}
}

signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%lld %lld",&a,&b);
		adj[a].pb(b);
		adj[b].pb(a);
	}

	dfs(1);
	if(ck)
	{
		cout<<n*(n-1)/2 - m;
	}
	else
	{
		int cnt = 0;
		for(int i=1;i<=n;i++)
		{
			cnt += color[i];
		}
		cout<<cnt*n - cnt*cnt - m;
	}
}