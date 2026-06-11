#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <deque>
#include <numeric>
#include <map>
#include <stack>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF 1000000000000

using namespace std;
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

class UnionFind {
public:
    vector < int > par; // 各元の親を表す配列
    vector < int > siz; // 素集合のサイズを表す配列(1 で初期化)

    // Constructor
    UnionFind(int sz_): par(sz_), siz(sz_, 1) {
        for (int i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }
    void init(int sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1);
        for (int i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
    }

    // Member Function
    // Find
    int root(int x) { // 根の検索
        while (par[x] != x) {
            x = par[x] = par[par[x]]; // x の親の親を x の親とする
        }
        return x;
    }

    // Union(Unite, Merge)
    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        // merge technique（データ構造をマージするテク．小を大にくっつける）
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool same(int x, int y) { // 連結判定
        return root(x) == root(y);
    }

    int size(int x) { // 素集合のサイズ
        return siz[root(x)];
    }
};

int main () {
	int N, M;
    cin >> N >> M;
	vector<pii> bridges(M);
	int u,v;
	rep(i,M) {
		cin >> u >> v;
		bridges[i] = pii(--u,--v);
	}
	UnionFind uf(N);
	vector<ll> ans(M);
	ans[M-1] = 1LL * N*(N-1)/2;
	for (int i = M-2; i >= 0; --i) {
		int u = bridges[i+1].first;
		int v = bridges[i+1].second;
		if (uf.same(u,v))
			ans[i] = ans[i+1];
		else
		{
			ans[i] = ans[i+1] - 1LL * uf.size(u) * uf.size(v);
			uf.merge(u,v);
		}
	}
	rep(i,M) cout << ans[i] << endl;
    return 0;
}