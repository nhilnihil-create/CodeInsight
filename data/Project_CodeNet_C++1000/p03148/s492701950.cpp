#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> in(n);
  for (int i = 0; i < n; i++) {
    int t, d;
    cin >> t >> d;
    in[--t].push_back(d);
  }
  for (int i = 0; i < n; i++) sort(in[i].rbegin(), in[i].rend());
  long long cur = 0;
  long long ans = 0;
  priority_queue<int, vector<int>, greater<int>> que;
  sort(in.rbegin(), in.rend());
  // for (int i = 0; i < n; i++) {
  //   for (int j : in[i]) cerr << j << " ";
  //   cerr << endl;
  // }
  for (int i = 0; i < min(n, k); i++) {
    if (in[i].empty()) continue;
    cur += in[i][0];
    for (int j = 1; j < (int) in[i].size(); j++) {
      que.push(in[i][j]);
      cur += in[i][j];
    }
    while ((int) que.size() > max(0, k - (i + 1))) {
      cur -= que.top();
      que.pop();
    }
    ans = max(ans, cur + 1LL * (i + 1) * (i + 1));
  }
  cout << ans << endl;
  return 0;
}