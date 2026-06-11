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
  UnionFind uf(n);
  for (int i=0; i<m; i++) {
    int x, y, z;
    cin>>x>>y>>z;
    --x;
    --y;
    uf.unite(x, y);
  }
  set<int> s;
  for (int i=0; i<n; i++) {
    if (s.find(uf.find(i)) == s.end()) {
      s.insert(uf.find(i));
    }
  }
  cout<<s.size()<<endl;
}