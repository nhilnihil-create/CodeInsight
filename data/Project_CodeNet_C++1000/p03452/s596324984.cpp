#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> g[100005];
vector<long long> dist(100005, 1LL << 60);
int n, m;
void dfs(int x) {
	for (auto &p : g[x]) {
		int to = p.first;
		long long d = p.second;
		if (dist[to] != 1LL << 60) {
			if (dist[to] != dist[x] + d) {
				cout << "No" << endl;
				exit(0);
			}
			continue;
		}
		dist[to] = dist[x] + d;
		dfs(to);
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int l, r, d;
		cin >> l >> r >> d;
		l--, r--;
		g[l].emplace_back(r, d);
		g[r].emplace_back(l, -d);
	}
	for (int i = 0; i < n; i++) {
		if (dist[i] != 1LL << 60) continue;
		dist[i] = 0;
		dfs(i);
	}
	cout << "Yes" << endl;
	return 0;	
}