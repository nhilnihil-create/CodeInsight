
// D - Decayed Bridges

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

class DisjointSet {
public:
	vector<int> rank;
	vector<int> parent;

	DisjointSet() {}

	// 0, 1, ... size-1 をそれぞれ唯一の要素とする
	// size個の互いに素な集合を作成
	DisjointSet(int size) {
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
};

int A[500000];
int B[500000];
int n_connected[500000];
ll inconvinience[500000];

ll convinience(ll n) {
	return n * (n-1) / 2;
}

int main() {
	int N, M;
	cin >> N >> M;

	for (int i=0; i<M; i++) {
		cin >> A[i] >> B[i];
		A[i]--;
		B[i]--;
	}

	reverse(A, A+M);
	reverse(B, B+M);

	for (int i=0; i<N; i++) {
		n_connected[i] = 1;
	}

	DisjointSet ds = DisjointSet(N);
	inconvinience[0] = convinience(N);
	for (int i=0; i<M-1; i++) {
		if (ds.same(A[i], B[i])) {
			inconvinience[i+1] = inconvinience[i];
		} else {
			int n_A = n_connected[ds.findSet(A[i])];
			int n_B = n_connected[ds.findSet(B[i])];
			int n_C = n_A + n_B;
			ds.unite(A[i], B[i]);
			int C = ds.findSet(A[i]);
			n_connected[C] = n_C;
			inconvinience[i+1] = inconvinience[i] + convinience(n_A) + convinience(n_B) - convinience(n_C);
		}

	}

	reverse(inconvinience, inconvinience+M);

	for (int i=0; i<M; i++) {
		cout << inconvinience[i] << endl;
	}

	return 0;
}