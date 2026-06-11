#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class UnionFind {
public:
	vector <int> par;  // 各元の親を表す配列
	vector <int> rank; // 素集合のランクを表す配列(0 で初期化)

	UnionFind(int n) : par(n), rank(n) {
		init(n);
	}

	void init(int n) {
		par.resize(n); for (int i = 0; i < n; ++i) par[i] = i;
		rank.assign(n, 0);
	}

	int root(int x) {
		if (par[x] == x) return x;
		else return root(par[x]);
	}

	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (rank[x] < rank[y]) {
			par[x] = y;
		}
		else { // rank[y] < rank[x]
			par[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
		}
		return true;
	}

	bool isSame(int x, int y) { // 連結判定
		return root(x) == root(y);
	}

	int getRank(int x) {        // 素集合のランク
		return rank[root(x)];
	}
};

int main() {

	int n, m; cin >> n >> m;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
	}
	UnionFind tree(n);

	for (int i = 0; i < m; i++) {
		int x, y; cin >> x >> y;
		x--;
		y--;
		tree.unite(x, y);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (tree.isSame(i, p[i])) ans++;
	}	
	cout << ans << endl;
	return 0;
}