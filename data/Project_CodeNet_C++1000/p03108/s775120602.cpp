#include <iostream>
#include <fstream>
#include <cstdlib>
#include <math.h>
#include <utility>
#include <algorithm>
#include <functional>
#include <vector>
#include <numeric>
#include <bits/stdc++.h>

#define int long long

struct edge {
    int to;
    int cost;
};

using namespace std;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vb = vector<bool>;
using qi = queue<int>;
using P = pair<int, int>;
using graph = vector<vector<edge>>;
// using graph = vector<vector<int>>;


#define FOR(i, a, b) for (int i = a; i < (b); i++)
#define REP(i,n) for(int i=0;i<n;i++)
#define delim(i, n) cout << (i == n-1 ? "\n" : " ");

struct UnionFind {
    vi par;
    vi size;
    UnionFind(int n) : par(n), size(n) {
        REP(i, n) par[i] = i;
        REP(i, n) size[i] = 1;
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx != ry) {
            size[rx] += size[ry];
            size[ry] = size[rx];
        }
        par[rx] = ry;
    }

    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int get_size(int x) {
        return size[root(x)];
    }
};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int inf = 1LL << 60;
// const int inf = 100000000;
const int mod = 1000000007;

const int maxn = 1e5;
int n, m;
vi a(maxn), b(maxn), inconv(maxn);

signed main () {
	cin.tie(0);
   	ios::sync_with_stdio(false);

    cin >> n >> m;
    REP(i, m) cin >> a[m-i-1] >> b[m-i-1];
    REP(i, m) {a[i]--; b[i]--;}

    UnionFind tree(n);
    inconv[0] = n*(n-1)/2;
    REP(i, m-1) {
        inconv[i+1] = inconv[i];
        if (!tree.same(a[i], b[i])) {
            inconv[i+1] -= tree.get_size(a[i]) * tree.get_size(b[i]);
            tree.unite(a[i], b[i]);
        }
    }
    REP(i, m) {
        cout << inconv[m-i-1] << "\n";
    }
}