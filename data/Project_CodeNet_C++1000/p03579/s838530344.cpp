#pragma GCC optimize("O3", "unroll-loops")

#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

int n, m;
vector<vector<int>> g;
vector<int> color;
bool bi = true;

void dfs(int s) {
	static vector<bool> visited(n, false);
	visited[s] = true;
	for (auto nx : g[s]) {
		if (color[s] == color[nx]) bi = false;
		else color[nx] = color[s] == 1 ? 0 : 1;
		if (!visited[nx]) dfs(nx);
	}
}

signed main() {
	cin >> n >> m;
	g.resize(n); color.resize(n, -1);
	color[0] = 1;
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	if (bi) { // 二分グラフ
		int cnt_1 = 0;
		for (auto ci : color)
			if (ci)
				++cnt_1;
		ll mx = (ll)cnt_1 * ((ll)n - (ll)cnt_1);
		cout << (mx - m) << endl;
	}
	else {
		cout << ((ll)n * ((ll)n - 1) / 2 - m) << endl;
	}
	return 0;
}