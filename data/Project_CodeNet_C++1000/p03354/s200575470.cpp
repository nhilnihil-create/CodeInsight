#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

#ifdef _DEBUG
#include "debug.h"
#else
#define debug(...)
#define print(...)
#endif

struct UnionFind {
	vector<int> data;

	UnionFind(int sz) {
		data.assign(sz, -1);
	}

	void unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return;
		if (data[x] > data[y]) swap(x, y);
		data[x] += data[y];
		data[y] = x;
	}

	int find(int k) {
		if(data[k] < 0) return(k);
		return data[k] = find(data[k]);
	}

	bool same(int x, int y)	{
		return find(x) == find(y);
	}

	int size(int k)	{
		return -data[find(k)];
	}
};

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i, n) {cin >> a[i]; a[i]--;}

    UnionFind uf(n);
    rep(i, m) {
        int x, y; cin >> x >> y;
        x--; y--;
        uf.unite(x, y);
    }

    int ans = 0;
    rep(i, n) {
        if (uf.same(a[i], i)) ans++;
    }

    debug(uf.data);

    cout << ans << endl;
}