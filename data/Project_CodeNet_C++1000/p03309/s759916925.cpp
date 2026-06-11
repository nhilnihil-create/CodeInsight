#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 2e5 + 5;

ll a[MAX];
int main() {
  ll n;
  cin >> n;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    a[i] -= i + 1;
  }
  sort(a, a + n);
  ll val = a[n >> 1];
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += abs(a[i] - val);
  }
  cout << ans << endl;
  return 0;
}
