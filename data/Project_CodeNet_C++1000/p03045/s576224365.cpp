#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

struct UnionFind
{
  vector<int> par;
  vector<int> sizes;
  int counts;

  UnionFind(int n) : par(n), sizes(n, 1)
  {
    rep(i,n)
      par[i] = i;
    counts = n;
  }

  int find(int x)
  {
    if (x == par[x])
      return x;
    return par[x] = find(par[x]);
  }

  void unite(int x, int y)
  {
    x = find(x);
    y = find(y);

    if (x == y)
      return;

    if (sizes[x] < sizes[y])
      swap(x, y);

    par[y] = x;
    sizes[x] += sizes[y];
    counts--;
  }

  bool same(int x, int y)
  {
    return find(x) == find(y);
  }

  int size(int x)
  {
    return sizes[find(x)];
  }

  int count()
  {
    return counts;
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  UnionFind u = UnionFind(n);
  rep(i, m)
  {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    u.unite(x, y);
  }
  cout << u.count() << endl;
}