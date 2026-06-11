#include <iostream>

using namespace std;

typedef long long ll;

int main () {
  ll a, b, c, k;
  cin >> a >> b >> c >> k;

  ll ans = a - b;
  if (k % 2 == 1) ans *= -1;

  cout << ans << endl;
}
