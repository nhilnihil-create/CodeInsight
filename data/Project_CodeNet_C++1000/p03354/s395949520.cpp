#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int MAX = 100000;

int n, m;
vector<int> p;
vector<vector<int>> g;
int seen[MAX];

void dfs(int v, set<int> &a, set<int> &b) {
	seen[v] = 1;
	a.insert(v);
	b.insert(p[v]);
	for (int nv : g[v]) {
		if (seen[nv] != 0) continue;
		dfs(nv, a, b);
	}
}

int main() {
	cin >> n >> m;
	g.assign(n, vector<int>());
	p.assign(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (seen[i] != 0) continue;
		set<int> a, b;
		vector<int> v;
		dfs(i, a, b);
		set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(v, v.end()));
		ans += v.size();
	}
	cout << ans << endl;
	return 0;
}