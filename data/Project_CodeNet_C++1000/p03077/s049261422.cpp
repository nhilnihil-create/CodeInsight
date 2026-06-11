#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n;
  ll a[5];
  cin >> n;
  for (int i = 0; i < 5; i++) {
    cin >> a[i];
  }

  ll mn = *min_element(a, a + 5);
  ll ans = (n + mn - 1) / mn + 4LL;

  cout << ans << endl;
  return 0;
}
