#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll cur = 0;
  ll l = 0;
  ll ans = 0;
  for (int r = 0; r < n; r++) {
    while (cur & a[r]) {
      cur ^= a[l];
      l++;
    }
    cur ^= a[r];
    ans += r - l + 1;
  }
  cout << ans << endl;
  return 0;
}
