// In the name of God

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int n, c[N];
vector<pair<int,int>> adj[N];

void dfs(int u, int p, int col) {
	c[u] = col;
	for(auto v : adj[u]) {
		if(v.first == p) continue;
		dfs(v.first, u, col ^ v.second);
	}
}	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for(int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		w = w & 1;
		u--;
		v--;
		adj[u].push_back(make_pair(v, w));
		adj[v].push_back(make_pair(u, w));
	}

	dfs(0, 0, 0);

	for(int i = 0; i < n; i++) cout << c[i] << "\n";

	return 0;
}
