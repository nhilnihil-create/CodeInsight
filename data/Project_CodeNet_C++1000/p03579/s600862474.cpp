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

struct Vertex
{
	int color;
	Vertex(int a) : color(a) {}
	Vertex() : Vertex(0) {}
};

using vertex = Vertex;

struct Edge
{
	int to;
	Edge(int t) : to(t) {}
	Edge() {}
};
using edge = Edge;
using graph = Graph<vertex, edge>;

long long res[3];

template<class V, class E>
bool is2graph_dfs(Graph<V, E>& G, int pos, int par = -1, int color = 1)
{
	if (par == -1) {
		if (G.v[pos].color) return true;
	}
	if (G.v[pos].color && G.v[pos].color != color) return false;
	if (G.v[pos].color) return true;
	G.v[pos].color = color;
	res[color]++;
	for (auto& n : G.e[pos]) {
		if (n.to == par) continue;
		if (!is2graph_dfs(G, n.to, pos, 3 - color)) return false;
	}
	return true;
}

template<class V, class E>
bool is2graph(Graph<V, E>& G)
{
	for (int i = 0; i < G.size(); i++) {
		if (!is2graph_dfs(G, i)) return false;
	}
	return true;
}

int main()
{
	int N, M;
	cin >> N >> M;
	graph G(N);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		G.add_edge(a, b);
		G.add_edge(b, a);
	}
	if (is2graph(G)) {
		cout << res[1] * res[2] - M << endl;
	} else {
		cout << (long long) N * (N - 1) / 2 - M << endl;
	}
}
