#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

struct UnionFind {
    // data[i] = 親ID if i == 子 else -size 
    vector<int> data;
    UnionFind(int n=0): data(n, -1) {}
    // 根のIDを聞く。再帰で。くっつけながら。
    int find(int x) {
        if (data[x] < 0) return x;
        return data[x] = find(data[x]);
    }
    // くっつける
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (data[x] > data[y]) swap(x, y);
        // size更新
        data[x] += data[y];
        // くっつけ
        data[y] = x;
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
    int size(int x) { return -data[find(x)]; }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> bridges(m);
    rep(i, m) cin >> bridges[i].first >> bridges[i].second;
    UnionFind uf(n);
    vector<ll> ans(m);
    ll tmpAns = (ll)n * (n-1) / 2;
    for (int i=m-1; i > -1; i--) {
        ans[i] = tmpAns;
        int a = bridges[i].first, b = bridges[i].second;
        --a; --b;
        if (!uf.same(a, b)) tmpAns -= (ll)uf.size(a) * uf.size(b);
        uf.unite(a, b);
    }
    rep(i, m) cout << ans[i] << endl;
    return 0;
}