#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

ll fn(ll n, ll m) {
  ll maxVal = max(n, m);
  ll minVal = min(n, m);
  while (minVal != 0) {
    ll tmp = maxVal % minVal;
    maxVal = max(tmp, minVal);
    minVal = min(tmp, minVal);
  }
  return maxVal;
}

int main() {
  ll n, x;
  cin >> n >> x;

  vector<ll> a(n, 0);
  for (long i = 0; i < n; i++) {
    ll tmp;
    cin >> tmp;
    a.at(i) = abs(tmp - x);
  }

  ll ans = a.at(0);
  for (long i = 1; i < n; i++) {
    ans = fn(a.at(i), ans);
  }
  cout << ans << endl;
}
