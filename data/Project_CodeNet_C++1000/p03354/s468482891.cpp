#include <bits/stdc++.h>
using namespace std;

struct UnionFindTree {
	vector<int> par;

	UnionFindTree(int N) : par(N) {
		for (int i = 0; i < N; i++) par[i] = i;
	}

	int root(int x) {
		if (par[x] == x) return x;
		else return par[x] = root(par[x]);
	}

	void unite(int x, int y) {
		int rx = root(x);
		int ry = root(y);
		if (rx == ry) return;
		else par[rx] = root(ry); // rxの親はryにする
	}

	bool same(int x, int y) {
		if (root(x) == root(y)) return true;
		else return false;
	}
};

int main(void) {
	int N, M; cin >> N >> M;
	vector<int> P(N);
	for (int i = 0; i < N; i++) cin >> P[i], P[i]--;

	UnionFindTree uf_tree(N);

	for (int i = 0; i < M; i++) {
		int x, y; cin >> x >> y;
		x--, y--;
		uf_tree.unite(x, y);
	}

	int res = 0;
	for (int i = 0; i < N; i++) {
		if (uf_tree.same(i, P[i])) res++;
	}

	cout << res << endl;

	return 0;
}