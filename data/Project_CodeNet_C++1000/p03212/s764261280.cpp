#include <bits/stdc++.h>

#include <iostream>
//#include <algorithm>
// #include <iomanip>
#define ll long long
#define map unordered_map
#define set unordered_set
#define pll pair<ll, ll>
#define vll vector<ll>

using namespace std;

const ll MOD = 1000000007LL;
const ll INF = (1LL << 60LL);

int main() {
  ll N;
  scanf("%lld", &N);

  vector<ll> nums(15);
  for (ll i = 0; i < nums.size(); i++) {
    nums[i] = -1;
  }
  nums[0] = 0;

  ll ans = 0;
  for (;;) {
    for (ll j = 0; j < nums.size(); j++) {
      if (nums[j] == -1) {
        nums[j] = 3;
      } else {
        nums[j] += 2;
      }
      if (nums[j] <= 7) {
        break;
      }
    }
    // adjust
    for (int i = nums.size() - 2; i >= 0; i--) {
      if (nums[i] > 7) {
        nums[i] = 3;
      }
    }
    ll n = 0;
    ll b = 1;

    bool found3 = false;
    bool found5 = false;
    bool found7 = false;
    for (ll k = 0; k < nums.size(); k++) {
      if (nums[k] < 0) {
        break;
      }
      if (nums[k] == 3) found3 = true;
      if (nums[k] == 5) found5 = true;
      if (nums[k] == 7) found7 = true;

      n += nums[k] * b;
      b *= 10LL;
    }
    if (n > N) {
      break;
    }
    if (found3 && found5 && found7) {
      ans++;
    }
    // print
    // for (ll k = nums.size() - 1; k >= 0; k--) {
    //   if (nums[k] >= 0) {
    //     cout << nums[k];
    //   }
    // }
    // cout << endl;
    // cout << n << endl;
  }

  cout << ans << endl;
}
