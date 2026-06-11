#include <bits/stdc++.h>
using namespace std;
void err() {
  cout << -1 << endl;
  exit(0);
}
void dfs (int crr, int dpt, vector<vector<int>>& grh, long long& cnt) {
  cnt += dpt;
  for (int nxt : grh[crr]) {
    dfs(nxt, dpt + 1, grh, cnt);
  }
}
int main() {
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
  vector<vector<int>> grh(n);
  for (auto it = d.rbegin(); next(it) != d.rend(); it++) {
    auto i = mp[*it];
    long long ptv = *it - n + 2 * sz[i];
    auto jt = lower_bound(d.begin(), d.end(), ptv);
    if (jt == d.end() || *jt != ptv) err();
    auto p = mp[*jt];
    grh[p].push_back(i);
    sz[p] += sz[i];
  }
  long long cnt = 0;
  int rt = mp[d[0]];
  dfs(rt, 0, grh, cnt);
  if (d[0] != cnt) err();
  for (int crr = 0; crr < n; crr++) {
    for (int nxt : grh[crr]) {
      cout << crr + 1 << ' ' << nxt + 1 << endl;
    }
  }
  return 0;
}
