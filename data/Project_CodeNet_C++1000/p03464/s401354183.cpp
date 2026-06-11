#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  int k;
  cin >> k;
  ll a[100005];
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  ll mn = 2;
  ll mx = 2;
  for (int i = k - 1; i >= 0; i--) {
    // [L, R]のaの倍数のminは、ceil(L/a)*a
    //                  maxは、floar(R/a)*a
    ll amn = (mn + a[i] - 1) / a[i] * a[i];
    ll amx = mx / a[i] * a[i];
    if (amn > mx) {
      cout << -1 << endl;
      return 0;
    }
    mn = amn;
    mx = amx + a[i] - 1;
  }
  cout << mn << " " << mx << endl;
}
