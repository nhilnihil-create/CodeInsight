#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define myPair pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define qmax priority_queue<int>
#define qmin priority_queue<int,vector<int>,greater<int>>
#define all(x) x.begin(),x.end()
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORR(i,a,b) for(int i = a; i >= b; i--)

const int mxn = 1e5 + 10, mod = 1e9 + 7;
vector<int> g[mxn];
int n, s;
int dp[mxn][2];
bool c[mxn][2];

// dp[u][col] = number of ways to color the subtree rooted at 'u'
// 				if u is colored with color 'col'

int f(int u, int col, int par)
{
	if(c[u][col])
		return dp[u][col];

	if(col)
	{
		dp[u][col] = 1;
		for(int v : g[u])
		{
			if(v != par)
				dp[u][col] = (dp[u][col] * f(v, 0, u)) % mod;
		}
	}
	
	else
	{
		dp[u][col] = 1;
		for(int v : g[u])
		{
			if(v != par)
			{
				int ans = (f(v, 0, u) + f(v, 1, u)) % mod;
				dp[u][col] = (dp[u][col] * ans) % mod;
			}
		}
	}
	c[u][col] = 1;
	return dp[u][col];
}

int32_t main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	FOR(i, 1, n)
		g[i].clear();

	memset(c, 0, sizeof(c));

	FOR(i, 1, n - 1)
	{
		int u,v;	cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	int ans = (f(1, 0, -1) + f(1, 1, -1)) % mod;
	cout << ans;

	return 0;
}
