// 7/4
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> X(M), Y(M), Z(M);
    rep(i, M) cin >> X[i] >> Y[i] >> Z[i];

    // UnionFind uf(2*N);
    // rep(i, M) {
    //     int x = X[i];
    //     int y = Y[i];
    //     if (Z[i]%2) {
    //         // X, Yは偶奇が等しい
    //         uf.unite(x, y);
    //         uf.unite(x+N, y+N);
    //     } else {
    //         // X, Yは偶奇が異なる
    //         uf.unite(x, y+N);
    //         uf.unite(x+N, y);
    //     }
    // }

    // set<int> st;
    // rep(i, 2 * N) {
    //     st.insert(uf.find(i));
    // }
    // cout << st.size() / 2 << endl;

    UnionFind uf(N);
    rep(i, M) {
        uf.unite(X[i]-1, Y[i]-1);
    }
    set<int> st;
    rep(i, N) st.insert(uf.find(i));
    cout << st.size() << endl;
}