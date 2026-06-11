#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  ll a, b, c, k;
  cin >> a >> b >> c >> k;
  ll ans;
  if (k % 2 == 0) {
    ans = a - b;
  }
  else {
    ans = b - a;
  }
  if (ans > 1000000000000000000) {
    cout << "Unfair" << endl;
  }
  else {
    cout << ans << endl;
  }
  return 0;
}