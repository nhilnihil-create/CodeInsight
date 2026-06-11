#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> sum(n);
  for (int i = 0; i < n; ++i) {
    cin >> sum[i];
  }
  for (int i = 1; i < n; ++i) {
    sum[i] += sum[i - 1];
  }
  ll ans = 1e18;
  int left = 0, right = 2;
  //切れ目の真ん中は n-3 こ
  for (int i = 1; i <= n - 3; ++i) {
    if (i == right)
      right++;
    ll pre_gap = sum[i];
    //左の切れ目を探す
    for (int j = left; j < i; ++j) {
      ll gap = abs(sum[i] - sum[j] - sum[j]);
      if (gap > pre_gap)
        break;
      else {
        pre_gap = gap;
        left = j;
      }
    }
    //右の切れ目を探す
    pre_gap = sum.back() - sum[i];
    for (int j = right; j <= n - 2; ++j) {
      ll gap = abs(sum.back() - sum[j] - (sum[j] - sum[i]));
      if (gap > pre_gap)
        break;
      else {
        pre_gap = gap;
        right = j;
      }
    }
    // cout << left << " " << i << " " << right << endl;
    ll p = sum[left], q = sum[i] - p, r = sum[right] - p - q,
       s = sum.back() - p - q - r;
    ans = min(ans, max({p, q, r, s}) - min({p, q, r, s}));
  }
  cout << ans << endl;
}