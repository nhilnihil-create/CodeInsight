#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int a[n];

  // m = a1*...*aN
  // m mod ai = 0
  // m - 1 mod ai = -1 mod ai
  //              = ai - 1
  // ai - 1 は mod a1 で考えたときの最大値
  // よって m = a1*...*aN - 1 とすればよい
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    a--;
    ans += a;
  }
  cout << ans << endl;

  return 0;
}
