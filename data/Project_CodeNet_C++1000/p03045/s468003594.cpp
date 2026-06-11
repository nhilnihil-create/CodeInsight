#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
  vector<int> par;
  vector<int> rank;

  UnionFind(int n = 1)
  {
    init(n);
  }

  void init(int n = 1)
  {
    par.resize(n);
    rank.resize(n);
    for (int i = 0; i < n; ++i)
      par[i] = i, rank[i] = 0;
  }

  int root(int x)
  {
    if (par[x] == x)
      return x;
    int r = root(par[x]);
    return par[x] = r;
  }

  bool same(int x, int y)
  {
    return root(x) == root(y);
  }

  bool unite(int x, int y)
  {
    x = root(x);
    y = root(y);
    if (x == y)
      return false;
    if (rank[x] < rank[y])
      swap(x, y);
    if (rank[x] == rank[y])
      ++rank[x];
    par[y] = x;
    return true;
  }
};

int main()
{
  int64_t N, M, x, y, z;
  cin >> N >> M;
  UnionFind uf(N);
  for (int i = 0; i < M; i++)
  {
    cin >> x >> y >> z;
    uf.unite(x - 1, y - 1);
  }
  map<int, int> mp;
  for (auto p : uf.par)
    mp[uf.root(p)]++;
  cout << mp.size() << endl;
}
