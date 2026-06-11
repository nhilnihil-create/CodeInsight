#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, u, v, dp[MX];
vi adj[MX];

ii dfs (int u, int p) {
	ii res(0, u);
	for (int v : adj[u])
		if (v != p)
			res = max(res, dfs(v, u));
	if (p != -1) res.fi++;
	return res;
}

int obtRes (int u) {
	if (dp[u] != -1) return dp[u];
	if (u == 0) return dp[u] = 0;
	if (u == 1) return dp[u] = 1;
	if (u == 2) return dp[u] = 0;
	return dp[u] = !obtRes(u-1) || !obtRes(u-2);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(dp, -1, sizeof(dp));
	
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	if (obtRes(dfs(dfs(1, -1).se, -1).fi + 1)) cout << "First" << endl;
	else cout << "Second" << endl;

	return 0;
}
