#include "bits/stdc++.h"
using namespace std;
using LL=long long;

const int INF = 1'000'000'000;
const long long INFLL = 1'000'000'000'000'000'000;

using Weight=int;
using P=pair<Weight, int>;
struct Edge {
	int to; Weight cost;
	Edge(int _to, Weight _cost) :to(_to), cost(_cost) {}
};
struct Edge2 { int u, v; Weight cost; };
using Graph=vector<vector<Edge>>;

int BipartiteGraph(const Graph& graph) {
	int V = graph.size(), White = 0;
	vector<int> Cr(V);

	function<bool(int, int)> dfs = [&](int v, int c) {
		Cr[v] = c;
		White += c == 1;
		for (auto e : graph[v]) {
			if (Cr[e.to] == c)return false;
			if (Cr[e.to] == 0 && !dfs(e.to, -c))return false;
		}
		return true;
	};

	for (int i = 0; i < V; i++) {
		if (Cr[i] == 0) {
			if (!dfs(i, 1))return -1;
		}
	}
	return White;
}

int main() {
	int n, m; cin >> n >> m;
	Graph g(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		g[a].emplace_back(b, 1);
		g[b].emplace_back(a, 1);
	}

	int b = BipartiteGraph(g);
	if (b == -1) {
		cout << (LL)n * (LL)(n - 1) / 2LL - (LL)m << endl;
	} else {
		cout << (LL)b * (LL)(n - b) - (LL)m << endl;
	}
}