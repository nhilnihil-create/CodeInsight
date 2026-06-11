#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


// サンプルだとちゃんと答えが出るのに、同じサンプルでのテストがRE139になる。理由が分からない。
/* UnionFind：素集合系管理の構造体(union by size)
    isSame(x, y): x と y が同じ集合にいるか。 計算量はならし O(α(n))
    unite(x, y): x と y を同じ集合にする。計算量はならし O(α(n))
    treeSize(x): x を含む集合の要素数。
*/
struct UnionFind {
    vector<int> size, parents;
    UnionFind() {}
    UnionFind(int n) {  // make n trees.
        size.resize(n, 0);
        parents.resize(n, 0);
        for (int i = 0; i < n; i++) {
            makeTree(i);
        }
    }
    void makeTree(int x) {
        parents[x] = x;  // the parent of x is x
        size[x] = 1;
    }
    bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }
    bool unite(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);
        if (x == y) return false;
        if (size[x] > size[y]) {
            parents[y] = x;
            size[x] += size[y];
        } else {
            parents[x] = y;
            size[y] += size[x];
        }
        return true;
    }
    int findRoot(int x) {
        if (x != parents[x]) {
            parents[x] = findRoot(parents[x]);
        }
        return parents[x];
    }
    int treeSize(int x) {
      return size[findRoot(x)];
    }
};

int main() {
  ll n, m;
  cin >> n >> m;
  vector<int> A(m), B(m);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    A[i] = a;
    B[i] = b;
  }

  vector<ll> ans(m + 1, 0);
  ans[m] = n * (n - 1) / 2;
  UnionFind tree(n);
  for(int i = m - 1; i >= 0; i--) {
    if (tree.findRoot(A[i]) == tree.findRoot(B[i])) {
      ans[i] = ans[i + 1];
    } else {
      ans[i] = ans[i + 1] - tree.treeSize(A[i]) * tree.treeSize(B[i]);
    }
    tree.unite(A[i], B[i]);
  }
  
  rep(i, m) cout << ans[i + 1] << endl;
  return 0;
}