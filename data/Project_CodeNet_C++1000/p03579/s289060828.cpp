#include <bits/stdc++.h>
using namespace std;

vector<int> edge[110000];
int color[110000];

bool dfs(int v, int c = 0) {
	color[v] = c;
	for (auto x : edge[v]) {
		if (color[x] != -1) {
			if (color[x] == c) return false;
		} else if (!dfs(x, c ^ 1)) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	fill(color, color + 110000, -1);
	if (dfs(0)) {
		int black = count(color, color + n, 0);
		int white = count(color, color + n, 1);
		cout << long(black) * white - m << endl;
	} else {
		cout << long(n) * (n - 1) / 2 - m << endl;
	}
}