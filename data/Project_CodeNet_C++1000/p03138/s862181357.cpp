#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, k;
  cin >> n >> k;
  int d = 0;
  while ((1LL << d) <= k) d++;

  ll nums[61] = {};
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    for (int j = 0; j < 61; j++) {
      nums[j] += (a & (1LL << j)) >> j;
    }
  }

  ll dp_limit = 0, ans = 0;
  bool limit = true;

  for (int i = 60; i >= 0; i--) {
    if (i < d) {
      if ((k & (1LL << i)) == 0) {
        if (!limit) {
          if (nums[i] >= n - nums[i]) ans += nums[i] * (1LL << i);  // select 0
          else ans += (n - nums[i]) * (1LL << i);   //select 1
        }
        dp_limit += nums[i] * (1LL << i);   // select 0
      }
      else {
        if (nums[i] >= n - nums[i]) {   // select 0
          ans = max(ans, dp_limit) + nums[i] * (1LL << i);
          dp_limit += nums[i] * (1LL << i);
          limit = false;
        }
        else {    // select 1
          if (!limit) ans += (n - nums[i]) * (1LL << i);
          else {
            ans = dp_limit + nums[i] * (1LL << i);  // select 0
            limit = false;
          }
          dp_limit += (n - nums[i]) * (1LL << i);
        }
      }

    }
    else {
      dp_limit += nums[i] * (1LL << i);
    }
  }

  cout << max(ans, dp_limit) << endl;

  return 0;
}