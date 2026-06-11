#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define MOD 1000000007
#define ar array
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int n;
vector<vector<int>> adj;
vector<int> parent;
vector<int> visited;
vector<int> color_white;
vector<int> color_black;

void dfs(int u, int p) {
	parent[u] = p;
	visited[u] = true;
	for (int v : adj[u]) {
		if (v != p && !visited[v]) {
			dfs(v, u);
		}
	}
	return;
}

int ways_to_color(int u, char color) {
	if (color == 'W') {
		if (color_white[u] != -1) return color_white[u];
		int children = 0;
		for (int v : adj[u]) {
			if (v != parent[u]) {
				children++;
			}
		}
		if (children == 0) {
			color_white[u] = 1;
			return 1;
		}
		int res = 1;
		for (int v : adj[u]) {
			if (v != parent[u]) {
				// res += ways_to_color(v, 'W'); res %= MOD;
				// res += ways_to_color(v, 'B'); res %= MOD;
				res *= (ways_to_color(v, 'W') + ways_to_color(v, 'B')) % MOD;
				res %= MOD;
			}
		}
		color_white[u] = res;
		return res;
	}
	if (color == 'B') {
		if (color_black[u] != -1) return color_black[u];
		int children = 0;
		for (int v : adj[u]) {
			if (v != parent[u]) {
				children++;
			}
		}
		if (children == 0) {
			color_black[u] = 1;
			return 1;
		}
		int res = 1;
		for (int v : adj[u]) {
			if (v != parent[u]) {
				res *= ways_to_color(v, 'W'); res %= MOD;
				res %= MOD;
			}
		}
		color_black[u] = res;
		return res;
	}
}

int32_t main() {
	fast_io;

	// int t; cin >> t;
	// while (t--) {
		
	// }
	cin >> n;
	adj.resize(n); parent.assign(n, -1); visited.assign(n, false);
	color_white.assign(n, -1); color_black.assign(n, -1);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, -1);
	int ans = ways_to_color(0, 'W') + ways_to_color(0, 'B');
	cout << ans % MOD << endl;

	// for (int i = 0; i < n; i++) {
	// 	cout << i + 1 << " " << color_white[i] << " " << color_black[i] << endl;
	// }
	// cout << endl;

	return 0;
}