#include <bits/stdc++.h>
using namespace std;
void err() {
  cout << -1 << '\n';
  exit(0);
}
void dfs (int crr, int dpt, vector<vector<int>>& grh, long long& cnt) {
  cnt += dpt;
  for (int nxt : grh[crr]) {
    dfs(nxt, dpt + 1, grh, cnt);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> d(n);
  map<long long, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    mp[d[i]] = i;
  }
  sort(d.begin(), d.end());
  vector<long long> sz(n, 1);
  vector<int> prt(n);
  vector<vector<int>> grh(n);
  vector<pair<int, int>> edg;
  for (auto it = prev(d.end()); it != d.begin(); it--) {
    auto i = mp[*it];
    long long prtv = *it - n + 2LL * sz[i];
    auto jt = lower_bound(d.begin(), d.end(), prtv);
    if (jt == d.end() || *jt != prtv) err();
    auto p = mp[*jt];
    prt[i] = p;
    grh[p].push_back(i);
    if (i == prt[i]) err();
    sz[prt[i]] += sz[i];
    edg.emplace_back(min(i, prt[i]), max(i, prt[i]));
  }
  long long cnt = 0;
  int rt = mp[d[0]];
  dfs(rt, 0, grh, cnt);
  if (d[0] != cnt) err();
  sort(edg.begin(), edg.end());
  for (auto const & e : edg) {
    cout << e.first + 1 << ' ' << e.second + 1 << '\n';
  }
  return 0;
}
