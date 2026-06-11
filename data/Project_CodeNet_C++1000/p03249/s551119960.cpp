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
  vector<pair<int, int>> edg;
  for (auto it = d.rbegin(); next(it) != d.rend(); it++) {
    auto i = mp.rbegin()->second;
    long long wnt = *it - n + 2 * sz[i];
    if (mp.find(wnt) == mp.end()) err();
    auto p = mp[wnt];
    sz[p] += sz[i];
    grh[p].push_back(i);
    edg.emplace_back(i, p);
    mp.erase(--mp.end());
  }
  int rt = mp.begin()->second;
  long long cnt = 0;
  dfs(rt, 0, grh, cnt);
  if (d[0] != cnt) err();
  for (auto const& e : edg) {
    cout << e.first + 1 << ' ' << e.second + 1 << '\n';
  }
  return 0;
}
