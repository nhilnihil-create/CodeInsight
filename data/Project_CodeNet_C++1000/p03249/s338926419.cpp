#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  vector<long long> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }

  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int i, int j) { return d[i] > d[j]; });
  int rt = ord.back(); ord.pop_back();

  map<long long, int> mp;
  for (int i = 0; i < n; i++) {
    mp[d[i]] = i;
  }
  vector<int> sz(n, 1), par(n, -1);
  vector<vector<int>> g(n);

  for (auto i : ord) {
    long long par_d = d[i] + sz[i] - (n - sz[i]);
    if (mp.count(par_d) == 0 || mp[par_d] == i || par[mp[par_d]] != -1) {
      cout << -1 << '\n';
      return 0;
    }
    par[i] = mp[par_d];
    g[par[i]].push_back(i);
    sz[par[i]] += sz[i];
  }

  // check dist[rt]
  long long real_d = 0;
  queue<pair<int,int>> q;
  q.emplace(rt, 0);
  while (q.size()) {
    auto v = q.front(); q.pop();
    real_d += v.second;
    for (auto u : g[v.first]) {
      q.emplace(u, v.second + 1);
    }
  }
  if (d[rt] != real_d) {
    cout << -1 << '\n';
    return 0;
  }

  for (int i = 0; i < n; i++) {
    if (par[i] != -1) {
      cout << i + 1 << ' ' << par[i] + 1 << '\n';
    }
  }

  return 0;
}
