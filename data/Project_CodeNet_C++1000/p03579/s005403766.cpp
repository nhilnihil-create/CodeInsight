#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1 << 20];
int chk[1 << 20][2];

void dfs(int u, int dis) {
	for (int v : adj[u]) {
		if (chk[v][dis ^ 1]) continue;
		chk[v][dis ^ 1] = 1;
		dfs(v, dis ^ 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	chk[1][0] = 1;
	dfs(1, 0);
	long long ans = (long long)n * (n - 1) / 2 - m;
	int cnt = 0;
	for (int i = 1; i <= n; i++) if (chk[i][0] && !chk[i][1]) cnt++;
	ans = ans - (long long)cnt * (cnt - 1) / 2;
	cnt = 0;
	for (int i = 1; i <= n; i++) if (!chk[i][0] && chk[i][1]) cnt++;
	ans = ans - (long long)cnt * (cnt - 1) / 2;
	cout << ans << endl;
	return 0;
}

