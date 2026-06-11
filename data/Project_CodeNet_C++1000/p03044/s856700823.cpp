#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

vector<P> edge[110000];
int color[110000];

void dfs(int v, int par = -1, int c = 0) {
	color[v] = c;
	for (auto p : edge[v]) {
		int x = p.first;
		int w = p.second;
		if (x == par) continue;
		if (w % 2 == 0)
			dfs(x, v, c);
		else
			dfs(x, v, c ^ 1);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		edge[u].push_back(P(v, w));
		edge[v].push_back(P(u, w));
	}
	dfs(0);
	for (int i = 0; i < n; i++) {
		cout << color[i] << endl;
	}
}