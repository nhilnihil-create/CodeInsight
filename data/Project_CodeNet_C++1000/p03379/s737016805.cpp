#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;

int main() {
  int n;
  cin >> n;
  vector<ll> x(n), s(n);
  for (int i = 0; i < n; i++) cin >> x[i];
  for (int i = 0; i < n; i++) s[i] = x[i];
  sort(s.begin(), s.end());

  ll med1 = s[n / 2];
  ll med2 = s[n / 2 - 1];

  ll ans(0);
  for (int i = 0; i < n; i++) {
    if (x[i] < med1) {
      ans = med1;
    } else {
      ans = med2;
    }
    printf("%ld\n", ans);
  }
}
