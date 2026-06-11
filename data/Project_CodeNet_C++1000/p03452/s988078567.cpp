
// Problem : D - People on a Line
// Contest : AtCoder Regular Contest 090
// URL : https://atcoder.jp/contests/arc090/tasks/arc090_b
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define size(x) (int)x.size()

const int N = 1e6 + 1, mod = 1e9 + 7, inf = 2e9;

struct adj_list {
	int v, w;
};

bool vis[N];
int n, m, cnt = 0, par[N], pos[N];
vector<adj_list> adj[N];

void dfs(int v) {
	vis[v] = 1;
	for (auto c : adj[v]) {
		int u = c.v, w = c.w;
		if (pos[u] == inf) {
			pos[u] = pos[v] + w;
		} else if (pos[u] != pos[v] + w) {
			cout << "No";
			exit(0);
		}
		if (vis[u]) {
			continue;
		}
		dfs(u);
	}
}

int main() { cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, -w});
	}
	fill(pos + 1, pos + n + 1, inf);
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			pos[i] = 0;
			dfs(i);
		}
	}
	cout << "Yes";
}
