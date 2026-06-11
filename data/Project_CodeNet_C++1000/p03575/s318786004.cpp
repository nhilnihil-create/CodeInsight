#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
#define int long long
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct UnionFind {
    vector<int> par;

    UnionFind (int n) : par (n, -1) {} //親は-1

    int root (int x) {
        if (par[x] < 0) return x; //自身が親
        else
            return par[x] = root (par[x]); //再帰
    }

    bool same (int x, int y) { return root (x) == root (y); }

    void merge (int x, int y) {
        x = root (x);
        y = root (y);
        if (x == y) return; //既に同じ根
        // xとyのサイズの大きいほうにまとめたい
        if (size (x) < size (y)) swap (x, y);
        par[x] += par[y]; //根のparは-(要素数)になる
        par[y] = x;       //親を更新
        return;
    }

    int size (int x) { return -par[root (x)]; }
};

signed main() {
    int n, m;
    cin >> n >> m;
    int a[m], b[m];
    rep (i, 0, m) {
        cin >> a[i] >> b[i];
        --a[i], --b[i];
    }
    int ans = 0;
    rep (i, 0, m) {
        UnionFind tree (n);
        rep (j, 0, m) {
            if (i == j) continue;
            tree.merge (a[j], b[j]);
        }
        int cnt = 0;
        rep (i, 0, n) {
            if (tree.root (i) == i) cnt++;
        }
        if (cnt > 1) ans++;
    }
    cout << ans << "\n";
}