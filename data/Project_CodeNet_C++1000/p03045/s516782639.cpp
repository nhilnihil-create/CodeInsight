#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)

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
    bool isRoot(int x) { return x == findRoot(x); }
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
    int treeSize(int x) { return size[findRoot(x)]; }
};

int main() {
  int n,m,x,y,z;
  cin >> n >> m;
  UnionFind U(n);
  for(int i = 0; i < m; i++) {
    cin >> x >> y >> z;
    U.unite(x-1,y-1);
  }
  int ans = 0;
  for(int i = 0; i < n; i++) {
    if (U.isRoot(i)) ans++;
  }
  cout << ans << endl;
  return 0;
}
