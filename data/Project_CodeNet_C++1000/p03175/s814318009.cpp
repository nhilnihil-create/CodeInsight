#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5, mod = 1e9 + 7;
int N;
vector<int> adj[MAXN];
ll dp[MAXN][2];

ll rec(int u, int p, int c)
{
	if (dp[u][c] != -1)
		return dp[u][c];
	ll tot = 0, ways = 1;
	for (int v : adj[u])
	{
		if (v == p)
			continue;
		ways = ways * rec(v, u, 0) % mod;
	}
	tot = ways;
	if (c == 0)
	{
		ways = 1;
		for (int v : adj[u])
		{
			if (v == p)
				continue;
			ways = ways * rec(v, u, 1) % mod;
		}
		tot = (tot + ways) % mod;
	}
	return dp[u][c] = tot;
}

int main()
{
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(dp, -1, sizeof(dp));
	ll ans = rec(0, -1, 0);
	cout << ans;

	return 0;
}