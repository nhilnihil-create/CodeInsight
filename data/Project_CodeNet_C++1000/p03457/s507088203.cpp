#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, t, x, y;
  cin >> n;
  ll now_t = 0, now_x = 0, now_y = 0;
  rep(i, n) {
    cin >> t >> x >> y;
    ll t1 = t - now_t;
    ll t2 = abs(now_x - x) + abs(now_y - y);
    if (t1 < t2 || (t1 - t2) % 2 != 0) {
      cout << "No" << endl;
      return 0;
    }
    now_t = t;
    now_x = x;
    now_y = y;
  }
  cout << "Yes" << endl;
  return 0;
}
