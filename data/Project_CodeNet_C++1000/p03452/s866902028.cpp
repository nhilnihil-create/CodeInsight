#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, M;
vector<vector<pair<ll, ll>>> Out;
vector<ll> Pos;
const ll INF = 1ll << 60;

void dfs(ll v, ll pos) {
  Pos[v] = pos;
  for (auto wd : Out[v]) {
    ll w = wd.first, d = wd.second;
    if (Pos[w] == INF) dfs(w, pos + d);
  }
}
bool check() {
  for (ll v = 0; v < N; ++v) {
    for (auto wd : Out[v]) {
      ll w = wd.first, d = wd.second;
      if (Pos[w] != Pos[v] + d) return false;
    }
  }
  return true;
}
int main() {
  cin >> N >> M;
  Out.resize(N);
  for (ll i = 0; i < M; ++i) {
    ll l, r, d;
    cin >> l >> r >> d;
    --l;
    --r;
    Out[l].push_back(make_pair(r, d));
    Out[r].push_back(make_pair(l, -d));
  }
  Pos.resize(N, INF);
  for (ll v = 0; v < N; ++v) {
    if (Pos[v] == INF) dfs(v, 0);
  }
  cout << (check() ? "Yes" : "No") << endl;
  return 0;
}
