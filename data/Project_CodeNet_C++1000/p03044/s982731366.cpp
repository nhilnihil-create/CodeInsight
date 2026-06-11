#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

using Edge = pair<int, int>;
using Graph = vector<vector<Edge>>;

Graph G;
vector<int> ans;

void dfs(int itr, int p, int c) {
	ans[itr] = c;
	for (int i = 0; i < G[itr].size(); i++) {
		if (G[itr][i].first == p) continue;
		if (G[itr][i].second & 1) dfs(G[itr][i].first, itr, 1 - c);
		else dfs(G[itr][i].first, itr, c);
	}
}

int main() {
	int N;
	cin >> N;

	ans.assign(N, 0);
	G.assign(N, vector<Edge>());

	for (int i = 0; i < N - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--; v--;
		G[u].push_back(Edge{ v,w });
		G[v].push_back(Edge{ u,w });
	}

	dfs(0, -1, 0);

	for (int i = 0; i < N; i++) cout << ans[i] << endl;
}