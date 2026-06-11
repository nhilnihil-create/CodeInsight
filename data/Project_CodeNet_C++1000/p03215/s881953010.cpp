#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<ll> sum;
  for (int i = 0; i < n; ++i) {
    ll res = 0;
    for (int j = i; j < n; ++j) {
      res += a[j];
      sum.push_back(res);
    }
  }
  ll ans = 0;
  for (int b = 40; b >= 0; --b) {
    int cnt = 0;
    for (int i = 0; i < sum.size(); ++i) {
      if ((sum[i] & (ans | 1ll << b)) == (ans | 1ll << b)) {
        cnt++;
      }
    }
    if (k <= cnt) {
      ans |= (1ll << b);
    }
  }
  cout << ans << endl;
  return 0;
}