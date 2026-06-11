#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i,n) for (int i = 0; i < (n); ++i)

struct UnionFindTree {
    vector<int> par;
    UnionFindTree(int n) : par(n) { // 全部根として初期化
        rep(i, n) par[i] = i;
    }
    int root(int x) { // 根を再帰的に探索
        if ( par[x] == x ) return x;
        else return par[x] = root(par[x]);
    }
    void unite(int x, int y) { // 異なる根の木を統合
        int rx = root(x);
        int ry = root(y);
        if ( rx != ry ) par[rx] = root(ry); // 根が異なる場合のみ統合
    }
    bool same(int x, int y) { // xとyが同じ根に属する場合はtrue, 属さない場合はfalse
        return (root(x) == root(y));
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    rep(i, n) {
        cin >> p[i];
        --p[i];
    }
    UnionFindTree uf_tree(n);
    rep(i, m) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        uf_tree.unite(x, y);
    }
    int ans = 0;
    rep(i, n) if ( uf_tree.same(i, p[i]) ) ++ans;
    cout << ans << endl;
    return 0;
}