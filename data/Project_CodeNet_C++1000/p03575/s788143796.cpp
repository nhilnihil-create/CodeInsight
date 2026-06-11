#include <bits/stdc++.h>

using namespace std;

struct UnionFind {  // The range of node number is from 0 to n-1
	//'rank[x]' is a rank of the union find tree the root of which is x.
	//'parents[x]' is the parent of x
	vector<int> rank, size, parents;

	// constructor
	UnionFind() {}
	UnionFind(int n) {  // make n trees.
		size.resize(n, 0);
		rank.resize(n, 0);
		parents.resize(n, 0);
		for (int i = 0; i < n; i++) {
			makeTree(i);
		}
	}
	// make a union find tree
	void makeTree(int x) {
		parents[x] = x;  // the parent of x is x
		rank[x] = 0;
		size[x] = 1;
	}

	// check whether the root of x is the same as that of y
	bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }

	//uniteはどちらかを選ぶこと！！！！！

	// unite two tree (ランク（木の高さ）が低くなるように繋げる場合）
	bool unite(int x, int y) {
		x = findRoot(x);
		y = findRoot(y);
		if (x == y) return false;
		if (rank[x] > rank[y]) {
			parents[y] = x;
		}
		else {
			parents[x] = y;
			if (rank[x] == rank[y]) {
				rank[y]++;
			}
		}
		return true;
	}

	// unite two tree (サイズ（頂点の数）が大きい方に小さい方を繋げる場合）
	//bool unite(int x, int y) {
	//	x = findRoot(x);
	//	y = findRoot(y);
	//	if (x == y) return false;
	//	if (size[x] > size[y]) {
	//		parents[y] = x;
	//		size[x] += size[y];
	//	}
	//	else {
	//		parents[x] = y;
	//		size[y] += size[x];
	//	}
	//	return true;
	//}

	//// 経路圧縮（全て根につなげる）する場合の根探しtravel the parents of tree recursivily to find root
	int findRoot(int x) {
		if (x != parents[x]) {
			parents[x] = findRoot(parents[x]);  // change the x's parent to the root of tree.
		}
		return parents[x];
	}
	//経路圧縮しない場合
	//int findRoot(int x) {
	//	if (x == parents[x])
	//		return x;
	//	return findRoot(parents[x]);
	//}

	int treeSize(int x) { return size[findRoot(x)]; }
};

int main() {

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(m);

	int in1, in2;
	for (int i = 0; i < m; i++) {
		cin >> in1 >> in2;
		a[i] = make_pair(in1-1, in2-1);
	}

	int res = 0;
	for (int i = 0; i < m; i++) {

		UnionFind tree(n);

		for (int j = 0; j < m; j++) {

			if (i == j) { continue; }

			tree.unite(a[j].first, a[j].second);
		}

		bool brkflg = false;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (tree.findRoot(j) != tree.findRoot(k)) {
					res++;
					brkflg = true;
					break;
				}
			}
			if (brkflg) { break; }
		}
	}

	cout << res << endl;

	return 0;
}