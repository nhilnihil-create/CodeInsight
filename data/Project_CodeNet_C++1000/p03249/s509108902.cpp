#include <bits/stdc++.h>
#define FOR(i,k,n) for(int i=(k);i<(int)(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;

int main() {
  int n;
  cin>>n;
  map<ll, pair<int, int>> m;
  REP(i,n) {
    ll d;
    cin>>d;
    m[d] = make_pair(1, i+1);
  }
  bool ok = true;
  vector<pair<int, int>> edges;
  while (m.size() > 1) {
    const auto itr = m.rbegin();
    ll d = itr->first;
    int k, i;
    tie(k, i) = itr->second;
    m.erase(prev(m.end()));
    ll diff = n-2*k;
    if (diff <= 0 || m.count(d - diff) == 0) {
      ok = false;
      break;
    }
    int l, j;
    tie(l, j) = m[d-diff];
    edges.emplace_back(j, i);
    m[d-diff] = make_pair(l+k, j);
  }
  if (ok) {
    reverse(ALL(edges));
    vector<ll> dist(n+1);
    for (auto p : edges) {
      int u, v;
      tie(u, v) = p;
      dist[v] = dist[u]+1;
    }
    ll sum = 0;
    for (auto d : dist) sum += d;
    if (sum == m.begin()->first) {
      for (auto p : edges) {
        int u, v;
        tie(u, v) = p;
        cout << u << ' ' << v << endl;
      }
    } else {
      cout << -1 << endl;
    }
  } else {
    cout << -1 << endl;
  }
  return 0;
}
