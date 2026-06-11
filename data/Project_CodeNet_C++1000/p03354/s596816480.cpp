#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<int> parent;
  vector<int> size;

  UnionFind(int n) : parent(n, -1), size(n, 1) {}

  int find(int i) {
    if (parent[i] == -1) {
      return i;
    }
    return parent[i] = find(parent[i]);
  }

  void unite(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j) {
      return;
    }
    if (size[i] < size[j]) {
      parent[i] = j;
      size[j] += size[i];
    } else {
      parent[j] = i;
      size[i] += size[j];
    }
  }
};

int main() {
  int n, m;
  cin>>n>>m;
  int p[n+1];
  for (int i=0; i<n; i++) cin>>p[i+1];
  UnionFind uf(n+1);
  for (int i=0; i<m; i++) {
    int x, y;
    cin>>x>>y;
    uf.unite(x, y);
  }
  int cnt = 0;
  for (int i=1; i<=n; i++) {
    if (uf.find(i) == uf.find(p[i])) {
      ++cnt;
    }
  }
  cout<<cnt<<endl;
}