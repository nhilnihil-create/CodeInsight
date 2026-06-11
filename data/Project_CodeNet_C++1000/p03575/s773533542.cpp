#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<bool>>;

vector<bool> seen;
void dfs(const Graph& G, long v) {
	seen[v] = true;

	for (long v2 = 0; v2 < G[v].size(); v2++) {
		if (!G[v][v2]) continue;
		if (seen[v2]) continue;
		dfs(G, v2);
	}
}

int main() {
	long n, m; cin >> n >> m;
	vector<long> a(m), b(m);
	Graph G(n, vector<bool>(n, false));
	for (long i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		G[a[i]][b[i]] = G[b[i]][a[i]] = true;
	}

	long ans = 0;

	for (long i = 0; i < m; i++) {
		G[a[i]][b[i]] = G[b[i]][a[i]] = false;
		seen.assign(n, false);
		dfs(G, 0);
		bool bridge = false;
		for (auto item: seen) if (!item) bridge = true;
		if (bridge) ans++;
		G[a[i]][b[i]] = G[b[i]][a[i]] = true;
	}

	cout << ans << endl;
	return 0;
}
