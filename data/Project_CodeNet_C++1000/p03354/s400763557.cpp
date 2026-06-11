#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(var, begin, end) for (int var = (begin); var <= (end); var++)
#define RFOR(var, begin, end) for (int var = (begin); var >= (end); var--)
#define REP(var, length) FOR(var, 0, length - 1)
#define RREP(var, length) RFOR(var, length - 1, 0)
#define EACH(value, var) for (auto value : var)
#define SORT(var) sort(var.begin(), var.end())
#define REVERSE(var) reverse(var.begin(), var.end())
#define RSORT(var) SORT(var); REVERSE(var)
#define OPTIMIZE_STDIO ios::sync_with_stdio(false); cin.tie(0); cout.precision(10); cout << fixed
#define endl '\n'

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n) {
      REP(i, n) par[i] = i;
    }

    int root(int x) {
      return par[x] == x ? x : par[x] = root(par[x]);
    }

    bool same(int x, int y) {
      return root(x) == root(y);
    }

    void unite(int x, int y) {
      x = root(x);
      y = root(y);

      if (x == y) return;

      par[x] = y;
    }
};


void solve(istream& cin, ostream& cout) {
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  REP(i, n) {
    cin >> p[i];
    p[i]--;
  }

  UnionFind uf(n);

  REP(i, m) {
    int x, y;
    cin >> x >> y;
    uf.unite(x - 1, y - 1);
  }
  int ans = 0;
  REP(i, n) {
    if (uf.same(i, p[i])) ans++;
  }
  cout << ans << endl;
}

#ifndef TEST
int main() {
  OPTIMIZE_STDIO;
  solve(cin, cout);
  return 0;
}
#endif
