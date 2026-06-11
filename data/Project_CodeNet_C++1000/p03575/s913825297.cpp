#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
#include <queue>
#include <cassert>
#include <iomanip>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define rALL(a) (a).rbegin(), (a).rend()
using namespace std;
using ll = long long;
using lP = pair<ll, ll>;
using iP = pair<ll, ll>;
const int iINF = 1001001001;
const long long llINF = 1LL << 60;

vector<vector<int>> edge;
vector<int> r;

struct UnionFind {
	vector<int> par; // par[i]:iの親の番号

	UnionFind(int N) : par(N) { // 最初は全てが根であるとして初期化
		for (int i = 0; i < N; ++i) par[i] = i;
	}

	int root(int x) { // データxが属する木の根を再帰で得る
		if (par[x] == x) return x;
		return par[x] = root(par[x]); // 経路圧縮
	}

	void unite(int x, int y) { // xとyの木を併合
		int rx = root(x);
		int ry = root(y);
		if (rx == ry) return;
		par[rx] = ry;
	}

	bool same(int x, int y) { // 2つのデータx,yが属する木が同じならtrueを返す
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
};

int main()
{
	// ABC075-C, UnionFindでも解いてみる
	int n, m; cin >> n >> m;
	vector<iP> edge(m);
	rep(i, m) {
		cin >> edge[i].first >> edge[i].second;
		edge[i].first--; edge[i].second--;
	}
	int ans = 0;
	rep(i, m) {
		UnionFind tree(n);
		rep(j, m) {
			if (i != j) tree.unite(edge[j].first, edge[j].second);
		}

		int parent = tree.root(0);
		bool ok = false;
		rep(j, n) {
			if (parent != tree.root(j)) ok = true;
		}
		if (ok) ans++;
	}
	cout << ans << endl;
	return 0;
}