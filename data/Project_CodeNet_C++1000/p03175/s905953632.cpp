#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define inlld(x) scanf("%lld", &x)
#define ind(x) scanf("%d", &x)
#define inlld2(x, y) scanf("%lld%lld", &x, &y)
#define inlld3(x, y, z) scanf("%lld%lld%lld", &x, &y, &z)
#define ind2(x, y) scanf("%d%d", &x, &y)
#define ind3(x, y, z) scanf("%d%d%d", &x, &y, &z)

const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

typedef long long ll;
typedef long double ld;

using namespace std;

ll n, dp[N][2];
vector<ll> adj[N];

void dfs(ll u, ll col, ll p)
{
	if (dp[u][col] != -1)
	{
		return;
	}
	dp[u][col] = 1;
	for (auto v : adj[u])
	{
		if (v == p)
			continue;
		if (col == 0)
		{
			dfs(v, 0, u);
			dfs(v, 1, u);
			dp[u][col] *= (dp[v][0] + dp[v][1]) % MOD;
		}
		else
		{
			dfs(v, 0, u);
			dp[u][col] *= dp[v][0];
		}
		dp[u][col] %= MOD;
	}
	// printf("%lld %lld %lld\n", u, col, dp[u][col]);
}

int main()
{
	inlld(n);
	for (ll a = 1; a < n; a++)
	{
		ll u, v;
		inlld2(u, v);
		adj[u].pb(v);
		adj[v].pb(u);
		dp[a][0] = dp[a][1] = -1;
	}
	dp[n][0] = dp[n][1] = -1;
	dfs(1, 0, 0);
	dfs(1, 1, 0);
	printf("%lld\n", (dp[1][0] + dp[1][1]) % MOD);
	return 0;
}