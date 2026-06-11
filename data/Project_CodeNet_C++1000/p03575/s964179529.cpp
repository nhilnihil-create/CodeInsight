#include <iostream>
#include <vector>

using namespace std;

struct UnionFind {
	vector<int> par;

	UnionFind(int N) : par(N) {
		for (int i = 0; i < N; i++) par[i] = i;
	}

	int root(int x) {
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	void unite(int x, int y) {
		int rx = root(x);
		int ry = root(y);
		if (rx == ry) return;
		par[rx] = ry;
	}

	bool same(int x, int y) {
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
};

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> a(M), b(M);

	for (int i = 0; i < M; i++) {
		cin >> a[i] >> b[i];
		a[i]--;
		b[i]--;
	}

	int bridge = 0;

	for (int j = 0; j < M; j++) {
		UnionFind tree(N);
		bool ok = true;
		for (int i = 0; i < M; i++) {
			if (i != j) tree.unite(a[i], b[i]);
		}
		for (int i = 0; i < N - 1; i++) {
			if (tree.root(i) != tree.root(i + 1)) ok = false;
		}
		if (!ok) bridge++;
	}

	cout << bridge << endl;


	return 0;
}
