#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll, ll> PLL;
#define chmax(x, y) do { x = max(x, y); } while(0)
#define chmin(x, y) do { x = min(x, y); } while(0)
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) \
  for (ll i = static_cast<ll>(a); i < static_cast<ll>(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, ) (__VA_ARGS__)  // NOLINT
template<typename T>
using reversed_priority_queue = std::priority_queue<T, std::vector<T>, std::greater<T> >;

bool ans[40000];

signed main() {
  ll N;
  cin >> N;
  if (N == 3) {
    cout << "2 5 63" << endl;
    return 0;
  } else if (N == 4) {
    cout << "2 5 20 63" << endl;
    return 0;
  } else if (N == 5) {
    cout << "2 3 6 9 10" << endl;
    return 0;
  } else if (N == 6) {
    cout << "2 3 6 9 10 12" << endl;
    return 0;
  }

  ans[2] = ans[3] = true;
  ll n = 2, x = 4, s = 2 + 3;
  while (n < N) {
    while (x % 6 == 1 || x % 6 == 5)
      x++;
    ans[x] = true;
    s += x, n++, x++;
  }

  if (s % 6 == 1) {
    ans[9] = false;
    while (x % 6 != 2)
      x++;
    ans[x] = true;
  } else if (s % 6 == 2) {
    ans[8] = false;
    while (x % 6 != 0)
      x++;
    ans[x] = true;
  } else if (s % 6 == 3) {
    ans[9] = false;
    while (x % 6 != 0)
      x++;
    ans[x] = true;
  } else if (s % 6 == 4) {
    ans[6] = false;
    while (x % 6 != 2)
      x++;
    ans[x] = true;
  } else if (s % 6 == 5) {
    ans[9] = false;
    while (x % 6 != 4)
      x++;
    ans[x] = true;
  }

  rep(i, 40000) {
    if (ans[i]) {
      cout << i << " ";
    }
  }
  cout << endl;

  return 0;
}
