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
	ll n, m;
	cin >> n >> m;
	int a[m], b[m];
	rep(i, m) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
	}
	UnionFind tree(n);
	vector<ll> ans(m + 1);
	ans[m] = n * (n - 1) / 2;
	for (int i = m - 1; i >= 0; i--) {
		if (tree.issame(a[i], b[i]))
			ans[i] = ans[i + 1];
		else {
			ans[i] = ans[i + 1] - tree.size(a[i]) * tree.size(b[i]);
			tree.merge(a[i], b[i]);
		}
	}
	rep(i, m) cout << ans[i + 1] << endl;
	return 0;
}