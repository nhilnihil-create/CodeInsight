#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

typedef std::vector<std::vector<int>> graph;

int main() {
  int n, m;
  cin >> n >> m;
  graph g(n);
  vi s(n);
  REP(i, n + m - 1) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    s[b]++;
    g[a].push_back(b);
  }
  int root = -1;
  REP(i, n) {
    if (s[i] == 0) {
      root = i;
    }
  }

  vi ans(n);
  ans[root] = 0;

  queue<int> q;
  q.push(root);
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (auto v : g[u]) {
      if (s[v] == 0)
        continue;
      s[v]--;
      if (s[v] == 0) {
        ans[v] = u + 1;
        q.push(v);
      }
    }
  }
  REP(i, n) { cout << ans[i] << endl; }
}
