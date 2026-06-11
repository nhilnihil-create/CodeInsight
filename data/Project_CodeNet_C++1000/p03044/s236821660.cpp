#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct edge
{
	int to, cost;
};

int main() {
	int n;
	cin >> n;
	vector<vector<edge>> g(n);
	for (int i = 0; i < n-1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	struct state
	{
		int v, parent;
	};
	int color[n]; fill(color, color+n, 0);
	stack<state> st;
	st.push({0, -1});
	while (!st.empty()) {
		state p = st.top(); st.pop();
		for (auto ne : g[p.v]) {
			if (ne.to == p.parent) continue;
			if (ne.cost%2 == 0) color[ne.to] = color[p.v];
			else color[ne.to] = 1 - color[p.v];
			st.push({ne.to, p.v});
		}
	}
	for (int i = 0; i < n; i++) {
		cout << color[i] << endl;
	}
	return 0;
}