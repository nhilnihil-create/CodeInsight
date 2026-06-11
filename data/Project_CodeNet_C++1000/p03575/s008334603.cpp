#include "bits/stdc++.h"
#include <set>

using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()
#define int long long
#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
#define mod 1000000007
#define INF 10e10
template <typename T>

void print(T x)
{
	std::cout << x << " ";
}

template <typename T>

void println(T x)
{
	std::cout << x << "\n";
}

struct UnionFind {
	vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
	vector <int> siz; // 素集合のサイズを表す配列(1 で初期化)

	UnionFind(int N) : par(N) { //最初は全てが根であるとして初期化
		for (int i = 0; i < N; i++) par[i] = i;
	}

	void init(int N) {
		par.resize(N);
		siz.assign(N, 1);  // resize だとなぜか初期化されなかった
		for (int i = 0; i < N; ++i) par[i] = i; // 初期では親は自分自身
	}


	int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	void unite(int x, int y) { // xとyの木を併合
		int rx = root(x); //xの根をrx
		int ry = root(y); //yの根をry
		if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
		if (siz[rx] < siz[ry]) swap(rx, ry);
		siz[rx] += siz[ry];
		par[ry] = rx; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
	}

	bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}

	int size(int x) { return siz[root(x)]; }
};

signed main(void) {
	int n, m;
	cin >> n >> m;
	vector<int>a(m);
	vector<int>b(m);
	rep(i, m) {
		cin >> a[i] >> b[i];
	}
	int ret = 0;
	rep(i, m) {
		UnionFind tree(n + 1);
		tree.init(n + 1);
		rep(j, m) {
			if (i == j)continue;
			tree.unite(a[j], b[j]);
		}
		if (!tree.same(a[i], b[i]))ret++;
	}
	print(ret);
}