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
  int64_t N, M, ans = 0;
  cin >> N >> M;
  vector<pair<int64_t, int64_t>> vp(M);
  for (int i = 0; i < M; i++)
  {
    cin >> vp[i].first >> vp[i].second;
    vp[i].first--;
    vp[i].second--;
  }
  UnionFind uf;
  for (int i = 0; i < M; i++)
  {
    uf.init(N);
    for (int j = 0; j < M; j++)
    {
      if (i == j)
        continue;
      uf.unite(vp[j].first, vp[j].second);
    }
    if (!uf.same(vp[i].first, vp[i].second))
      ans++;
  }
  cout << ans << endl;
}