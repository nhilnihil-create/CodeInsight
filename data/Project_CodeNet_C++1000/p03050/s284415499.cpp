#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n;
  cin >> n;

  int k = 1;
  ll ans = 0;
  while (1) {
    ll m = n / k - 1;
    if (k >= m) break;
    if (n % k == 0) ans += m;
    ++k;
  }
  cout << ans << endl;
  return 0;
}