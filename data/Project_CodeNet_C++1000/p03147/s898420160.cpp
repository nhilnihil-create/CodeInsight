#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 100;

int main() {
  ll n, h;
  cin >> n;
  int ans = 0, active = 0;
  rep(i, n) {
    cin >> h;
    if (active >= h) {
      active = h;
    } else {
      ans += h - active;
      active = h;
    }
  }
  cout << ans << endl;
  return 0;
}
