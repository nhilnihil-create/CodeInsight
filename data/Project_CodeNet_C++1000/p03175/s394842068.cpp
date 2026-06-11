//pragma GCC optimize("-Ofast")
#include <bits/stdc++.h>
using namespace std;
#define AC 0
#define mod 1000000007
vector< vector<int> > dp, g;
void dfs(int u, int p) {
	for(int i=0;i<g[u].size();i++)
		if (g[u][i] != p) {
			dfs(g[u][i], u);
			dp[u][0] = 1ll * dp[u][0] * (dp[g[u][i]][0] + dp[g[u][i]][1]) % mod % mod;
			dp[u][1] = 1ll * dp[u][1] * dp[g[u][i]][0] % mod;
		}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	dp.resize(n, vector<int>(2, 1));
	g.resize(n);
	for (int x, y; --n > 0;) {
		cin >> x >> y;
		g[x - 1].push_back(y - 1);
		g[y - 1].push_back(x - 1);
	}
	dfs(0, -1);
	cout << (dp[0][0] + dp[0][1]) % mod << '\n';
	return AC;
}