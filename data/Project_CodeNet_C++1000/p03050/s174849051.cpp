#include <iostream>
using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  // n = k(m+1)　なるmがお気に入りの数になりうる
  ll ans = 0;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ll m1 = n / i - 1;
      ll m2 = i - 1;
      if (m1 != 0 && n / m1 == n % m1) {
        ans += m1;
      }
      if (m1 != m2 && m2 != 0 && n / m2 == n % m2) {
        ans += m2;
      }
    }
  }
  cout << ans << endl;
}
