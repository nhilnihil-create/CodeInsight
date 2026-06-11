
// D - Equals

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

class DisjointSet {
public:
	int size;
	vector<int> rank;
	vector<int> parent;

	DisjointSet() {}

	// 0, 1, ... size-1 をそれぞれ唯一の要素とする
	// size個の互いに素な集合を作成
	DisjointSet(int size) {
		this->size = size;
		rank.resize(size, 0);
		parent.resize(size, 0);
		for (int i=0; i<size; i++) {
			makeSet(i);
		}
	}

	// 要素がXただ一つである新しい集合を作る
	void makeSet(int x) {
		parent[x] = x;
		rank[x] = 0;
	}

	// xとyが同じ集合に属しているかを判定する
	bool same(int x, int y) {
		return findSet(x) == findSet(y);
	}

	// 指定された2つの要素x, yを合併する
	void unite(int x, int y) {
		link(findSet(x), findSet(y));
	}

	// 低い方の木を高い方の木に合併
	void link(int x, int y) {
		if (rank[x] > rank[y]) {
			parent[y] = x;
		} else {
			parent[x] = y;
			if (rank[x] == rank[y]) {
				rank[y]++;
			}
		}
	}

	// 要素xが属する集合の代表の要素を求める
	int findSet(int x) {
		if (x != parent[x]) {
			parent[x] = findSet(parent[x]);
		}
		return parent[x];
	}

	// 集合の個数を求める
	int countSet() {
		int cnt = 0;
		for (int x=0; x<size; x++) {
			if (x == parent[x]) cnt++;
		}
		return cnt;
	}
};

int p[100000];

int main() {
	int N, M;
	cin >> N >> M;

	DisjointSet ds = DisjointSet(N);
	unordered_map<int, unordered_set<int>> grp_to_idx;

	for (int i=0; i<N; i++) {
		cin >> p[i];
		p[i]--;
	}

	for (int i=0; i<M; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;

		ds.unite(x, y);
	}

	for (int i=0; i<N; i++) {
		int grp = ds.findSet(p[i]);
		grp_to_idx[grp].insert(i);
	}

	int ans = 0;

	for (int i=0; i<N; i++) {
		int grp = ds.findSet(p[i]);
		if (grp_to_idx[grp].count(p[i]) >= 1) ans++;
	}

	cout << ans << endl;

	return 0;
}