#include <bits/stdc++.h>
using namespace std;

#define pll pair<long long, long long>

class UnionFind {
public:
	vector <long long> par; // 各元の親を表す配列
	vector <long long> siz; // 素集合のサイズを表す配列(1 で初期化)

	// Constructor
	UnionFind(long long sz_): par(sz_), siz(sz_, 1LL)
	{
		for (long long i = 0; i < sz_; ++i) {
			par[i] = i; // 初期では親は自分自身
		}
	}
	void init(long long sz_)
	{
		siz.assign(sz_, 1LL);  // assign: 再代入
		par.resize(sz_);  // resize: 再確保
		for (long long i = 0; i < sz_; ++i) {
			par[i] = i; // 初期では親は自分自身
		}
	}

	// Member Function
	// Find
	long long root(long long x)
	{
		// 根の検索
		while (par[x] != x) {
			x = par[x] = par[par[x]]; // x の親の親を x の親とする
		}
		return x;
	}

	// Union(Unite, Merge)
	bool merge(long long x, long long y)
	{
		x = root(x);
		y = root(y);
		if (x == y) {
			return false;
		}
		// merge technique（データ構造をマージするテク．小を大にくっつける）
		if (siz[x] < siz[y]) {
			swap(x, y);
		}
		siz[x] += siz[y];
		par[y] = x;
		return true;
	}

	// 連結判定
	bool issame(long long x, long long y)
	{
		return root(x) == root(y);
	}

	// 素集合のサイズ
    long long size(long long x)
	{
        return siz[root(x)];
    }
};

int main()
{
	long long N, M;
	long long node1, node2;
	cin >> N >> M;

	vector<pll> A(M);
	for (long long loop = 0; loop < M; ++loop) {
		cin >> node1 >> node2; --node1, --node2;
		A[loop].first = node1;
		A[loop].second = node2;
	}

	vector<long long> ans(M);
	ans[M-1] = (N*(N-1))/2;

	UnionFind uf(N);
	for (long long loop = M - 1; loop >= 1; --loop) {
		node1 = A[loop].first, node2 = A[loop].second;
		if (uf.issame(node1, node2)) {
			ans[loop - 1] = ans[loop];
		} else {
			ans[loop - 1] = ans[loop] - (uf.size(node1) * uf.size(node2));
			uf.merge(node1, node2);
		}
	}

	for (int loop = 0; loop < M; ++loop) {
		cout << ans[loop] << "\n";
	}

    return 0;
}
