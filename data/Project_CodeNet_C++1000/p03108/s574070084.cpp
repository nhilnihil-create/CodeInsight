#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct UnionFind {
	vector<int> p, s;
	
	UnionFind(int n) : p(n), s(n) {
		for (int i = 0; i < n; i++) {
			p[i] = i;
			s[i] = 1;
		}
	}
	
	int root(int x) {
		return p[x] == x ? x : p[x] = root(p[x]);
	}
	
	void unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return;
		if (s[x] < s[y]) swap(x, y);
		s[x] += s[y];
		p[y] = x;
	}
	
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	
	int size(int x) {
		return s[root(x)];
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
			ll as = uf.size(a[i]);
			ll bs = uf.size(b[i]);
			ans[i - 1] = ans[i] - as * bs;
			uf.unite(a[i], b[i]);
		}
	}
	
	rep(i, m) cout << ans[i] << endl;
	return 0;
}