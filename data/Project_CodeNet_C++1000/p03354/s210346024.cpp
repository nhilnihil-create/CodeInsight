#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

struct UnionFind
{
  vector<int> d;
  UnionFind(int n = 0) : d(n, -1) {}
  int find(int x)
  {
    if (d[x] < 0)
      return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y)
  {
    x = find(x);
    y = find(y);
    if (x == y)
      return false;
    if (d[x] > d[y])
      swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -d[find(x)]; }
};

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> p(N);
  vector<int> value_to_index(N);

  rep(i, N)
  {
    cin >> p[i];
    p[i]--;
    value_to_index[p[i]] = i;
  }
  UnionFind uf(N);
  rep(i, M)
  {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    uf.unite(x, y);
  }

  rep(i, N)
  {
    int swap_index = value_to_index[i];
    if (i == swap_index)
      continue;

    if (uf.same(i, swap_index))
    {
      swap(value_to_index[p[i]], value_to_index[p[swap_index]]);
      swap(p[i], p[swap_index]);
    }
  }

  int ans = 0;
  rep(i, N)
  {
    if (p[i] == i)
      ans++;
  }
  cout << ans << endl;
  return 0;
}