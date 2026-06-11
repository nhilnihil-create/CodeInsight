#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1000000007;

ll r(ll x, ll y) {
  if (y == 0) return 1;
  else if (y % 2 == 0) return r(x, y/2) * r(x, y/2) % mod;
  else return x * r(x, (y-1)/2) % mod * r(x, (y-1)/2) % mod;
}


int main() {
  ll n;
  cin >> n;
  ll a[n], b[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  
  ll p = 0;
  ll m = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= b[i]) {
      ll pp = a[i] - b[i];
      p += pp;
    }
    else {
      ll mm = b[i] - a[i];
      mm /= 2;
      m += mm;
    }
  }
  if (p > m) cout << "No" <<endl;
  else cout << "Yes" <<endl;
}
