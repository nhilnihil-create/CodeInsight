#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mxN = 1e5 + 5, mod = 1e9 + 7;
int N;
vector<int> adj[mxN];
int dp[mxN][2];

int rec(int u, int p, int pc) {
	if (dp[u][pc] != -1) {
		return dp[u][pc];
	}
	ll tot = 0, ways = 1;
	if (pc == 0) {
		for (int v : adj[u]) {
			if (v == p) {
				continue;
			}
			ways = (ways * rec(v, u, 1)) % mod;
		}
		tot = ways;
	}
	ways = 1;
	for (int v : adj[u]) {
		if (v == p) {
			continue;
		}
		ways = (ways * rec(v, u, 0)) % mod;
	}
	tot = (tot + ways) % mod;
	return dp[u][pc] = tot;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> N;
	int x, y;
	for (int i = 0; i < N - 1; i++) {
		cin >> x >> y;
		x--, y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	memset(dp, -1, sizeof(dp));
	int ans = rec(0, -1, 0);
	cout << ans;
	
	return 0;
}
