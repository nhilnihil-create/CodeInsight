#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() { 
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  vector<int> left(n + 1), right(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> left[i] >> right[i];
  }
  sort(right.begin(), right.end());
  sort(left.rbegin(), left.rend());
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    if (right[i] < left[i]) ans += 2 * (left[i] - right[i]);
  }
  cout << ans << endl;
  return 0;
}