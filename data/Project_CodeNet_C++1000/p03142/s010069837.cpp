#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define DUMP(x) cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for (ll i = m; i < n; i++)
#define IFOR(i, m, n) for (ll i = n - 1; i >= m; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)
#define FOREACH(x, a) for (auto&(x) : (a))
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main() {
  ll n, m;
  cin >> n >> m;
  vector<vector<ll>> to(n);
  vector<ll> deg(n, 0);
  REP(i, n + m - 1) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;
    to[b].push_back(a);
    deg[a]++;
  }

  stack<ll> st;
  REP(i, n) if (deg[i] == 0) st.push(i);
  // dp[i] = 頂点iを始点とするパス長の最大値
  vector<ll> topo, dp(n, 0);
  while (!st.empty()) {
    ll cv = st.top();
    st.pop();
    topo.push_back(cv);
    FOREACH(nv, to[cv]) {
      deg[nv]--;
      dp[nv] = max(dp[nv], dp[cv] + 1);
      if (deg[nv] == 0) st.push(nv);
    }
  }
  vector<ll> inv(n);
  REP(i, n) { inv[topo[i]] = i; }

  auto comp = [&inv](ll i, ll j) { return inv[i] < inv[j]; };

  REP(i, n) {
    if (SZ(to[i]) > 0) sort(ALL(to[i]), comp);
  }

  REP(i, n) {
    if (SZ(to[i]) == 0) {
      cout << 0 << endl;
      continue;
    }
    cout << to[i][0] + 1 << endl;
  }
}