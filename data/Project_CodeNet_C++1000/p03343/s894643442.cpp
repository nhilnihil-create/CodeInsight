#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto calc = [] (vector<vector<int>> v, int k, int q) {
    int n = (int) v.size();
    for (int i = 0; i < n; i++) sort(v[i].rbegin(), v[i].rend());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    for (int i = 0; i < n; i++) que.emplace(v[i].back(), i);
    int mi = 1 << 30, mx = 0;
    while (q > 0 && que.size()) {
      auto cur = que.top();
      que.pop();
      int idx = cur.second;
      int val = cur.first;
      if ((int) v[idx].size() < k) continue;
      mi = min(mi, val);
      mx = max(mx, val);
      v[idx].pop_back();
      q--;
      if (v[idx].size()) que.emplace(v[idx].back(), idx);
    }
    return (q == 0 ? mx - mi : 1 << 30);
  };
  int ans = 1 << 30;
  for (int i = 0; i < n; i++) {
    vector<vector<int>> v;
    v.push_back({});
    for (int j = 0; j < n; j++) {
      if (a[j] >= a[i]) v.back().push_back(a[j]);
      else if (v.back().size()) v.push_back({});
    }
    if (v.back().empty()) v.pop_back();
    ans = min(ans, calc(v, k, q));
  }
  cout << ans << endl;
  return 0;
}