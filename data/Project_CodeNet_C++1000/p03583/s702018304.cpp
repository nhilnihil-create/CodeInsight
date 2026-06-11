#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
  ll N;
  cin >> N;
  for (ll l = 1; l <= 3500; l ++) {
    for (ll k = 1; k <= 3500; k ++) {
      ll p = 4 * l * k - N * l - N * k;
      ll q = N * k * l;
      if (p > 0 && q % p == 0) {
        cout << l << ' ' << k << ' ' << q / p << endl;
        return 0;
      }
    }
  }
}