#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  ll k, a, b;
  cin >> k >> a >> b;
  if (b - a < 2) {
    cout << 1 + k << endl;
  } else {
    ll biscuit = 1;
    if (biscuit < a) {
      biscuit = a;
      k -= a - 1;
    }
    biscuit += k / 2 * (b - a);
    if (k % 2 == 1) biscuit++;
    cout << biscuit << endl;
  }
  return 0;
}