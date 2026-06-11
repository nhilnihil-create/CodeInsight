#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<ll>> a(n, vector<ll>(3));
  for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
  ll res = 0;
  for (int i = 0; i <= (1 << 3); i++) {
    vector<int> state(3, 1);
    for (int j = 0; j < 3; j++) 
      if ((1 << j) & i) 
        state[j] = -1;
    vector<ll> nums;
    for (int j = 0; j < n; j++) {
      ll cur = 0;
      for (int k = 0; k < 3; k++) {
        if (state[k] * a[j][k] > 0) cur += abs(a[j][k]);
        else cur -= abs(a[j][k]);
      }
      nums.push_back(cur);
    }
    sort(nums.rbegin(), nums.rend());
    ll ans = 0;
    for (int j = 0; j < m; j++)
      ans += nums[j];
    res = max(res, ans);
  }
  cout << res << '\n';
  return 0;
}
