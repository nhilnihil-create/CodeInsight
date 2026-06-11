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

vector<int> G[100100], cnt(100100, 0), ans(100100);

void bfs(int s) {
  queue<pair<int, int>> q;
  q.push({s, -1});
  while (!q.empty()) {
    int v = q.front().first, p = q.front().second;
    q.pop();
    ans[v] = p + 1;
    for (int u: G[v]) {
      if (--cnt[u] == 0) {
        q.push({u, v});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed << setprecision(25);

  int n, m;
  cin >> n >> m;
  rep(i, n - 1 + m) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    cnt[b]++;
  }

  rep(i, n) {
    if (cnt[i] == 0) {
      bfs(i);
      break;
    }
  }
  rep(i, n) cout << ans[i] << '\n';




  
  return 0;
}