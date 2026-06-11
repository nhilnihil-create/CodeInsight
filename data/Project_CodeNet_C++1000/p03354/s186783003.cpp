#include<iostream>
#include<vector>
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
	int N, M; cin >> N >> M;
	vector<int> p(N); for (auto&& x : p)cin >> x;

	int x, y;
	UnionFind UF(N);
	for (int i = 0; i < M; ++i) {
		cin >> x >> y;
		UF.unite(x - 1, y - 1);
	}

	int sum = 0;
	for (int i = 0; i < N; ++i) {
		if (UF.same(i, p.at(i) - 1)) {
			++sum;
		}
	}
	cout << sum << endl;

	return 0;
}