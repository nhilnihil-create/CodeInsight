#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
const ll MOD = 1000000007;
struct UnionFind {
	vector<int> par;
	UnionFind(int n) : par(n, -1) {}
	void init(int n) { par.assign(n, -1); }
	int root(int x) {
		if (par[x] < 0) return x;
		return par[x] = root(par[x]);
	}
	bool issame(int x, int y) { return root(x) == root(y); }
	bool merge(int x, int y) {
		x = root(x), y = root(y);
		if (x == y) return false;
		if (par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}
	int size(int x) { return -par[root(x)]; }
};
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	UnionFind tree(n);
	while (m--) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		x--, y--;
		tree.merge(x, y);
	}
	int ans = 0;
	for (auto p : tree.par) {
		if (p < 0) ans++;
	}
	cout << ans << "\n";
	return 0;
}