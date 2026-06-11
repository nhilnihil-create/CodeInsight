#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const ll INF = 1e18;
const long double EPS = 1e-10;
const int MAX = 100005;

vector<int> G[MAX];
vector<int> c(MAX, -1);
int color = 0;

void dfs(int u) {
  if (c[u] != -1) return;
  c[u] = color;
  for (int v: G[u]) {
    dfs(v);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  rep(i, n) {
    cin >> p[i];
    p[i]--;
  }
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    G[x - 1].push_back(y - 1);
    G[y - 1].push_back(x - 1);
  }

  rep(i, n) {
    if (c[i] == -1) {
      dfs(i);
      color++;
    }
  }

  set<int> id[color];
  rep(i, n) id[c[i]].insert(p[i]);

  int ans = 0;
  rep(i, n) {
    if (id[c[i]].find(i) != id[c[i]].end()) ans++;
  }
  cout << ans << endl;


  
  return 0;
}