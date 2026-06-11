#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, K; cin >> N >> K;
  vector<int> xs(N); for (auto &x : xs) cin >> x;
  int ans = 1e9;
  for (int l = 0, r; (r = l + K - 1) < N; ++l) ans = min({ans, abs(xs[l]) + abs(xs[r] - xs[l]), abs(xs[r]) + abs(xs[r] - xs[l])});
  cout << ans << endl;}