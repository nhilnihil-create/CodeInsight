#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const int INF = 1 << 30;
const long long MOD = 1000000000 + 7;
const double PI = acos(-1);

struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n) {
        //for (int i = 0; i < n; i++)par[i] = i;
        for (int i = 0; i < n; i++)par[i] = -1;
    }

    int root(int x) {
        //if (par[x] == x) return x;
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false; // 同じ木に属するのでmergeしない（そのまま）
        if (par[x] > par[y]) swap(x, y); // merge technique（-nがその木の要素数)
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    int size(int x) {
        return -par[root(x)]; // -nがノード数なのでマイナスかける
    }
};

int main() {
	int N, M; cin >> N >> M;
    UnionFind uf(N);
    rep(i, M) {
        int x, y, z; cin >> x >> y >> z;
        uf.merge(x - 1, y - 1);
    }
    map<int, int> mp;
    rep(i, N)mp[uf.root(i)] = 1;
    cout << mp.size();
}