#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
const int INF = 1000000007;

int n;
vector<P> G[1000005];
vector<int> ans;

void cal(int from, ll cur, ll dist) {
  if (dist % 2 == 1) {
    ans[cur] = 1;
  }
  for (P p : G[cur]) {
    if (p.first == from) continue;
    cal(cur, p.first, dist + p.second);
  }
}

int main() {
  cin >> n;
  ans.resize(n);
  rep(i, n - 1) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--, v--;
    G[u].push_back({v, w});
    G[v].push_back({u, w});
  }

  cal(-1, 0, 0);

  rep(i, n) { cout << ans[i] << endl; }
}