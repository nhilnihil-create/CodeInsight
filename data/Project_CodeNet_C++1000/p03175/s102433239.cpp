#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll dp[100001][2];
ll mod = 1e9+7;
class graph
{
public:
	ll v;
	list<ll> *adj;
	bool *visited;
	
	graph(ll v)
	{
		this->v = v;
		adj = new list<ll>[v];
		visited = new bool[v];
		for (ll i = 0; i < v; ++i)
		{
			visited[i] = false;
		}
	}

	void add(ll a, ll b)
	{
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	void dfs(ll v);
};

void graph::dfs(ll i)
{
	visited[i] = true;
	ll white = 1;
	ll black = 1;
	for(auto t: adj[i])
	{
		if(!visited[t])
		{
			dfs(t);
			white = (white*(dp[t][0]+dp[t][1]))%mod;
			black = (black*dp[t][1])%mod;
		}
	}
	dp[i][1] = white;
	dp[i][0] = black;
}

void solve()
{
	ll n;
	cin>>n;
	graph g(n);
	for (ll i = 0; i < n-1; ++i)
	{
		/* code */
		ll u,v;
		cin>>u>>v;
		g.add(u-1,v-1);
	}
	g.dfs(0);
	cout<<(dp[0][1]+dp[0][0])%mod<<endl;
}

int main()
{
	ll t = 1;
	// cin>>t;
	while(t--)
	{
		solve();
	}
}