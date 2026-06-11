#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct DisjointSet
{
  vector<int> par;
  DisjointSet(int n) : par(n, -1) {}
  void unite(int x, int y)
  {
    x = find(x);
    y = find(y);
    if (x == y)
      return;
    if (par[x] > par[y])
      swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int find(int x)
  {
    if (par[x] < 0)
      return x;
    int r = find(par[x]);
    return par[x] = r;
  }
  int sizeOf(int x) { return -par[find(x)]; }
};

int n, q, x, y;
string s;
long long a[6060];

int main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int m;
  cin >> m;
  vector<pair<int, int>> edge;
  for (size_t i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    --a, --b;
    edge.emplace_back(a, b);
  }

  int ans = 0;
  for (size_t i = 0; i < m; i++)
  {
    DisjointSet ds(n);
    for (size_t j = 0; j < m; j++)
    {
      if (i == j)
        continue;
      ds.unite(edge[j].first, edge[j].second);
    }
    if (ds.sizeOf(0) != n)
      ++ans;
  }

  cout << ans;

  return 0;
}
