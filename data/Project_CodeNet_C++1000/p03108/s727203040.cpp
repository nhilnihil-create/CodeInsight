#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)

struct UnionFind
{
  vector<int> sz, rank, p;

  UnionFind(int n)
  {
    sz.resize(n, 1);
    rank.resize(n, 0);
    p.resize(n);
    rep(i, n) p.at(i) = i;
  }

  int get_size(int x)
  {
    return sz.at(find(x));
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
    if (!same(x, y))
    {
      int tmp = sz.at(find(x)) + sz.at(find(y));
      sz.at(find(x)) = tmp;
      sz.at(find(y)) = tmp;
    }
    link(find(x), find(y));
  }
};

int main()
{
  ll N;
  int M;
  cin >> N >> M;
  UnionFind uf(N);
  vector<pair<int, int>> edge(M);
  rep(i, M)
  {
    int A, B;
    cin >> A >> B;
    A--;
    B--;
    edge.at(i) = make_pair(A, B);
  }
  reverse(edge.begin(), edge.end());
  vector<ll> ans(M);
  ans.at(0) = N * (N - 1) / 2;
  rep(i, M - 1)
  {
    int A, B;
    tie(A, B) = edge.at(i);
    if (!uf.same(A, B))
    {
      ans.at(i + 1) = ans.at(i) - (ll)uf.get_size(A) * (ll)uf.get_size(B);
    }
    else
    {
      ans.at(i + 1) = ans.at(i);
    }
    uf.unite(A, B);
  }
  reverse(ans.begin(), ans.end());
  rep(i, M) cout << ans.at(i) << endl;
}