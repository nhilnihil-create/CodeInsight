#include <bits/stdc++.h>
using namespace std;

class UnionFind {
public:
  vector<int> parent;
  UnionFind(int n) { parent = vector<int>(n, -1); }
  int root(int a) {
    if(parent[a] < 0)
      return a;
    return parent[a] = root(parent[a]);
  }
  int size(int a) { return -parent[root(a)]; }
  bool connect(int a, int b) {
    a = root(a);
    b = root(b);
    if(a == b)
      return false;
    if(size(a) < size(b))
      swap(a, b);
    parent[a] += parent[b];
    parent[b] = a;
    return true;
  }
};

int main() {
  int n, m, x, y, o = 0;
  cin >> n >> m;
  vector<int> p(n);
  for(int i = 0; i < n; i++)
    cin >> p.at(i);
  UnionFind uni(n);
  for(int i = 0; i < m; i++){
    cin >> x >> y;
    uni.connect(--x, --y);
  }
  for(int i = 0; i < n; i++)
    if(uni.root(p.at(i)-1)==uni.root(i))
      o++;
  cout << o << endl;
}
