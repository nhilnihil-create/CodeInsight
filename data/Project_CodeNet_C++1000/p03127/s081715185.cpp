#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

template <typename T>
T gcd(T a, T b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  ll ans = a[0];
  for (int i = 1; i < n; i++) {
    ans = min(ans, gcd(ans, a[i]));
  }
  cout << ans << endl;
}
