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
  ll n, X;
  cin >> n >> X;

  vector<ll> x(n + 1);
  for (int i = 0; i < n; i++) cin >> x[i];
  x[n] = X;

  sort(x.begin(), x.end());
  set<ll> s;
  for (int i = 0; i < n; i++) s.insert(x[i + 1] - x[i]);

  ll ans = *s.begin();
  for (auto itr = s.begin(); itr != s.end(); itr++) {
    ans = gcd(*itr, ans);
  }
  cout << ans << endl;
}
