#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

vector<int> G[200200];
vector<int> d(200200, -1);

void dfs(int v = 0, int p = -1) {
  for (int u: G[v]) {
    if (u == p) continue;
    d[u] = d[v] + 1;
    dfs(u, v);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  int n;
  cin >> n;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  d[0] = 0;
  dfs();
  int idx = 0, res = 0;
  rep(i, n) {
    if (chmax(res, d[i])) {
      idx = i;
    }
  }
  rep(i, n) d[i] = -1;
  d[idx] = 0;
  dfs(idx);
  res = 0;
  rep(i, n) {
    chmax(res, d[i]);
  }
  cout << (res % 3 != 1 ? "First" : "Second") << '\n';




  
  return 0;
}