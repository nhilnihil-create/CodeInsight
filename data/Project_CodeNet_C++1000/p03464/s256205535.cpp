#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

inline ll ceiling(ll a, ll m) { return (a + m - 1) / m; }

int main() {
  int k;
  cin >> k;
  vector<ll> a(k + 1);
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
  }
  ll mn = 2;
  ll mx = 2;
  for (int i = k; i > 0; i--) {
    // [L, R]のaの倍数のminは、ceil(L/a)*a
    //                  maxは、floar(R/a)*a
    ll amn = ceiling(mn, a[i]) * a[i];
    ll amx = mx / a[i] * a[i];
    if (amn > mx || amx < mn) {
      cout << -1 << endl;
      return 0;
    }
    mn = amn;
    mx = amx + a[i] - 1;
  }
  cout << mn << " " << mx << endl;
}
