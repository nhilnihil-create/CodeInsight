#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using pii = pair<int, int>;

struct UnionFind {
	vector<int> par;
	
	UnionFind(int n) : par(n) {
		for (int i = 0; i < n; i++) par[i] = i;
	}
	
	int root(int x) {
		return par[x] == x ? x : par[x] = root(par[x]);
	}
	
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	
	void unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return;
		par[x] = y;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}
	UnionFind u(n);
	rep(i, m) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		u.unite(x, y);
	}
	int ans = 0;
	rep(i, n) {
		if (u.same(i, p[i])) ans++;
	}
	cout << ans << endl;
	return 0;
}