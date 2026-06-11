#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct UnionFind {
	vector<int> p;
	
	UnionFind(int n) {
		p = vector<int>(n, -1);
	}
	
	int root(int x) {
		return p[x] < 0 ? x : p[x] = root(p[x]);
	}
	
	void unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return;
		if (p[x] > p[y]) swap(x, y);
		p[x] += p[y];
		p[y] = x;
	}
	
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	
	int size(int x) {
		return -p[root(x)];
	}
};

int main() {
	ll n, m;
	cin >> n >> m;
	vector<int> a(m), b(m);
	rep(i, m) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
	}
	UnionFind uf(n);
	vector<ll> ans(m);
	ans[m - 1] = (ll)n * (n - 1) / 2;
	for (int i = m - 1; i > 0; i--) {
		ans[i - 1] = ans[i];
		if (!uf.same(a[i], b[i])) {
			ll sa = uf.size(a[i]);
			ll sb = uf.size(b[i]);
			ans[i - 1] = ans[i] - sa * sb;
			uf.unite(a[i], b[i]);
		}
	}
	rep(i, m) cout << ans[i] << endl;
	return 0;
}