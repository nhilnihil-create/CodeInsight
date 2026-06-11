// 7/9
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
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
    ll N, M;
    cin >> N >> M;
    vector<int> A(M), B(M);
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--; B[i]--;
    }

    UnionFind uf(N);
    vector<ll> res;
    
    res.push_back(N * (N-1) / 2);
    for (ll i = M-1; i > 0; i--) {
        if (uf.same(A[i], B[i])) {
            res.push_back(res.back());
        } else {
            ll add = uf.size(A[i]) * uf.size(B[i]);
            uf.unite(A[i], B[i]);
            res.push_back(res.back() - add);
        }
    }

    for (ll i = M-1; i >= 0; i--) {
        cout << res[i] << endl;
    }
    return 0;
}