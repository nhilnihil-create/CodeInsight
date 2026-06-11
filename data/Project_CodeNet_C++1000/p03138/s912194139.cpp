#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll ans = 0;
  ll x = 0;
  for (int i = 0; i < 40; ++i) {
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      if ((a[j] >> 1ll * (39 - i)) & 1) {
        cnt++;
      }
    }
    if (n - cnt <= cnt) {
      ans += (1ll << (39 - i)) * cnt;
    } else {
      if (x + (1ll << (39 - i)) <= k) {
        ans += (1ll << (39 - i)) * (n - cnt);
        x += (1ll << (39 - i));
      } else {
        ans += (1ll << (39 - i)) * cnt;
      }
    }
  }
  cout << ans << endl;
  return 0;
}