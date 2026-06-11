// ABC097D - Equals

#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long int ull;
typedef long long int ll;

struct UnionFind {
	vector<int> par;
	vector<int> rank;
	vector<int> count;

	// n要素で初期化
	UnionFind(int n) {
		par.resize(n);
		rank.resize(n, 0);
		count.resize(n, 1);
		for (int i = 0; i < n; i++) {
			par[i] = i;
		}
	}

	// 木の根を求める。
	int find(int x) {
		if (par[x] == x) {
			return x;
		} else {
			return par[x] = find(par[x]);
		}
	}

	// xとyの属する集合を併合
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) {
			return;
		}
		
		count[x] += count[y];
		count[y] = count[x];
		if (rank[x] < rank[y]) {
			par[x] = y;
		} else {
			par[y] = x;
			if (rank[x] == rank[y]) {
				rank[x]++;
			}
		}
	}

	// xとyが同じ集合に属するか否か
	bool same(int x, int y) {
		return find(x) == find(y);
	}

	// xと同じ集合の要素数を返す。
	int getCount(int x) {
		return count[x];
	}
};

int main() {
	int N, M;
	cin >> N >> M;

	int p[N];
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}

	UnionFind tree(N+1);
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		tree.unite(x, y);
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (tree.same(p[i], i + 1)) {
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}
