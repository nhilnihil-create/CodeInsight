#include<bits/stdc++.h>
#define rep(i,n) for(int (i) = 0;(i) < (n);(i)++)
using namespace std;
typedef long long ll;

int main(void) {
  ll n, k;
  cin >> n >> k;

  ll ans = 0;


  for (ll b = n; b >= 1; b--) {
    ll q = n / b;
    ll r = n % b;

    ll sa = (b - 1) - r;

    ans += max(0LL, (b - k) * q) + max(0LL, b - k - sa);
  }

  if (k == 0) ans -= n;

  cout << ans << endl;

  return 0;
}