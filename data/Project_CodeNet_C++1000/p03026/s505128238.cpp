// 2020-09-01 21:46:26
// clang-format off
#include<bits/stdc++.h>
#ifdef LOCAL
#include "lib/debug.hpp"
#else
#define debug(...) 1
#endif
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define rep(i, n) REP(i, 0, (n))
#define repc(i, n) REPC(i, 0, (n))
#define REP(i, n, m) for (int i = (int)(n); i < (int)(m); i++)
#define REPC(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define REPCM(i, n, m) for (int i = (int)(n); i >= (int)(m); i--)
using namespace std;
using ll = long long;
using ld = long double;
using pr = pair<ll, ll>;
using vll = vector<ll>;
using vpr = vector<pr>;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } else return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } else return false; }

// clang-format on
const int V = 10010;
vector<int> G[V];
void answer() {
  int n;
  cin >> n;
  rep(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> c(n), ans(n, -1);
  int tot = 0;
  rep(i, n) {
    cin >> c[i];
    tot += c[i];
  }
  sort(RALL(c));
  tot -= c[0];
  queue<int> que;
  que.push(0);
  int ci = 0;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    ans[u] = c[ci++];
    for (int v : G[u]) {
      if (ans[v] == -1) {
        que.push(v);
      }
    }
  }
  cout << tot << '\n';
  rep(i, ans.size()) {
    if (i) cout << ' ';
    cout << ans[i];
  }
  cout << '\n';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  answer();
  return 0;
}