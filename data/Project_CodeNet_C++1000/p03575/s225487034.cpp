#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

struct UnionFind
{
  vector<int> rank, p;

  UnionFind(int n)
  {
    rank.resize(n, 0);
    p.resize(n);
    rep(i, n) p.at(i) = i;
  }

  int find(int x)
  {
    if (x != p.at(x))
    {
      p.at(x) = find(p.at(x));
    }
    return p.at(x);
  }

  bool same(int x, int y)
  {
    return find(x) == find(y);
  }

  void link(int x, int y)
  {
    if (rank.at(x) < rank.at(y))
      p.at(x) = y;
    else
    {
      p.at(y) = x;
      if (rank.at(x) == rank.at(y))
      {
        rank.at(x)++;
      }
    }
  }

  void unite(int x, int y)
  {
    link(find(x), find(y));
  }
};

int main()
{
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> edge(M);
  rep(i, M)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edge.at(i) = make_pair(a, b);
  }
  int ans = 0;
  rep(i, M)
  {
    UnionFind uf(N);
    int a, b;
    tie(a, b) = edge.at(i);
    rep(j, M)
    {
      if (j == i)
        continue;
      int b, c;
      tie(b, c) = edge.at(j);
      uf.unite(b, c);
    }
    if (!uf.same(a, b))
    {
      ans++;
    }
  }
  cout << ans << endl;
}