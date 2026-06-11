#include "bits/stdc++.h"
using namespace std;
vector<int>Col(100005);
struct Edge {
	int to, id;
	Edge(int to, int id) :to(to), id(id) {}
};
vector<Edge>g[100005];

void dfs(int v, int p = -1) {
	for (Edge e : g[v]) {
		if (p == e.to) {
			continue;
		}
		if( (0 == Col[v]&&0 == e.id)|| (1 == Col[v] && 1 == e.id)) {
			Col[e.to] = 0;
		}
		else{
			Col[e.to] = 1;
		}
		dfs(e.to,v);
	}
}

int main() {
	int N;
	cin >> N;
	for (int n = 0; n < N - 1; ++n) {
		int u, v,w;
		cin >> u >> v >>w;
		u--;
		v--;
		g[u].emplace_back(v, w%2);
		g[v].emplace_back(u, w%2);
	}
	Col[0] = 0;
	dfs(0);
	for (int n = 0; n < N; ++n) {
		cout << Col[n] << endl;
	}
	return 0;
}