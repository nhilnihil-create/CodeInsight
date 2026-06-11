#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct UnionFind {
	vector<int> p;
	
	UnionFind(int n) : p(n) {
		for (int i = 0; i < n; i++) p[i] = i;
	}
	
	int root(int x) {
		return p[x] == x ? x : p[x] = root(p[x]);
	}
	
	void unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x != y) p[x] = y;
	}
	
	bool same(int x, int y) {
		return root(x) == root(y);
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m);
	rep(i, m) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
	}
	int ans = 0;
	rep(i, m) {
		UnionFind uf(n);
		rep(j, m) {
			if (i == j) continue;
			uf.unite(a[j], b[j]);
		}
		if (!uf.same(a[i], b[i])) ans++;
	}
	cout << ans << endl;
	return 0;
}