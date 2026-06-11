#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

vector<int> tpsort(const vector<vector<int>>& g) {
	int V = g.size();
	vector<int> indeg(V, 0);
	stack<int> S;

	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			++indeg[g[i][j]];
		}
	}
	for (int i = 0; i < V; ++i) {
		if (indeg[i] == 0) { S.push(i); }
	}

	vector<int> ret;
	while (S.size() > 0) {
		int u = S.top(); S.pop();
		ret.push_back(u);
		for (int i = 0; i < g[u].size(); ++i) {
			--indeg[g[u][i]];
			if (indeg[g[u][i]] == 0) {
				S.push(g[u][i]);
			}
		}
	}
	return ret;
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> g(N);
	for (int i = 0; i < N - 1 + M; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].emplace_back(v);
	}

	auto t = tpsort(g);
	vector<int> ans(N, 0);
	for (auto v : t) {
		for (auto u : g[v]) {
			ans[u] = v + 1;
		}
	}
	for (auto v : ans) { cout << v << "\n"; }

	return 0;
}
