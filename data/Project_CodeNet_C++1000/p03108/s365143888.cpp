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

  int get_size(int i) {
    return size[find(i)];
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
  pair<int, int> p[m];
  for (int i=0; i<m; i++) {
    cin>>p[i].first>>p[i].second;
    --p[i].first;
    --p[i].second;
  }
  long long sum = 1LL * n * (n - 1) / 2;
  long long ans[m];
  for (int i=m-1; i>=0; i--) {
    ans[i] = sum;
    int a = p[i].first;
    int b = p[i].second;
    if (uf.find(a) != uf.find(b)) {
      long long size_a = uf.get_size(a);
      long long size_b = uf.get_size(b);
      sum -= size_a * size_b;
      uf.unite(a, b);
    }
  }
  for (int i=0; i<m; i++) {
    cout<<ans[i]<<endl;
  }
}