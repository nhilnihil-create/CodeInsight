#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  if (a + b > n + 1 || 1LL * a * b < n) {
    cout << -1 << '\n';
    return 0;
  }
  int cur = n;
  vector<vector<int>> seq;
  while (cur >= 1 && a > 0) {
    seq.push_back({cur--});
    a--;
  }
  int it = 0;
  while (cur >= 1) {
    while (cur >= 1 && (int) seq[it].size() < b) seq[it].push_back(cur--);
    it++;
  }
  vector<int> ans;
  for (int i = (int) seq.size() - 1; i >= 0; i--) for (int j : seq[i]) ans.push_back(j);
  for (int i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}