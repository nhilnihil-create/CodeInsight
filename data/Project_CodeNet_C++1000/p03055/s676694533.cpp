#include <bits/stdc++.h>

using namespace std;

template<class V, class E>
struct Graph
{
	int sz;
	vector<V> v;
	vector<vector<E>> e;
	Graph(int n) : sz(n), v(n), e(n) {}
	template<class... Args>
	inline void assign_vertex(int pos, Args... args) {
		v[pos] = V(args...);
	}
	template<class... Args>
	inline void add_edge(int pos, Args... args) {
		e[pos].emplace_back(args...);
	}
	inline int size() {
		return sz;
	}
};
struct Vertex{};
using vertex = Vertex;
struct Edge
{
	int to;
	int cost;
	Edge(int t, int c) : to(t), cost(c) {}
	Edge() {}
};

using edge = Edge;
using graph = Graph<vertex, edge>;

int Diameter(graph& G) {
	auto dfs = [&G](auto f, int start, int& goal, int par = -1) -> int {
		goal = start;
		int res = 0;
		for (auto& e: G.e[start]) {
			if (e.to == par) continue;
			int t;
			int r = f(f, e.to, t, start);
			r += e.cost;
			if (r > res) {
				res = r;
				goal = t;
			}
		}
		return res;
	};
	int g;
	dfs(dfs, 0, g);
	return dfs(dfs, g, g);
}

int main() {
	int N;
	cin >> N;
	graph G(N);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--;b--;
		G.add_edge(a, b, 1);
		G.add_edge(b, a, 1);
	}
	int d = Diameter(G);
	if (d % 3 == 1) cout << "Second" << endl;
	else cout << "First" << endl;
}