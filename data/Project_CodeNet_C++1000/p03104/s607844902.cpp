#include <bits/stdc++.h>
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define repr(i, a, n) for (ll i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

ll sol(ll n) {
  if (n < 0)
    return 0;
  int r = n % 4;
  if (r == 0)
    return n;
  if (r == 1)
    return 1;
  if (r == 2)
    return n + 1;
  if (r == 3)
    return 0;
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
 
  ll a, b;
  cin >> a >> b;
  cout << (sol(a - 1) ^ sol(b)) << endl;
}
