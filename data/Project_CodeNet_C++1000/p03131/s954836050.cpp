#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int k, a, b;
  cin >> k >> a >> b;
  ll ans;
  if (b - a <= 2) {
    ans = k + 1;
  } else {
    if (a - 1 > k) ans = k + 1;
    else {
      ans = a;
      k -= a - 1;
      ans += (ll)(b - a) * (k / 2) + k % 2;
    }
  }
  cout << ans << endl;
  return 0;
}