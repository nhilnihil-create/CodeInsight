#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10, inf = 1e9 + 1;
int dis[N], mark[N], n, m, mn, mx;
vector<pair<int, int> > gr[N];
void dfs(int v) {
	mark[v] = 1;
	for (auto p : gr[v]) {
		int u = p.first, w = p.second;
		if (mark[u]) {
			if (dis[u] != dis[v] + w) {
				cout << "No";
				exit(0);
			}
		}
		else {
			dis[u] = dis[v] + w;
			dfs(u);
		}
	}
	return;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		gr[x].push_back({y, w});
		gr[y].push_back({x, -w});
	}
	for (int i = 0; i < n; i++) {
		if (!mark[i]) {
			mn = mx = 0;
			dfs(i);
			if (mx - mx > inf) {
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
	return 0;
}
