#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void()
#endif

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i].first;
    x[i].second = i;
  }
  sort(x.begin(), x.end());
  vector<int> ans(n);
  for (int i = 0; i < n / 2; i++) {
    ans[x[i].second] = x[n / 2].first;
  }
  for (int i = n / 2; i < n; i++) {
    ans[x[i].second] = x[n / 2 - 1].first;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}