#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  if (b - a + 1 < 2 * k) {
    rep(i, b - a + 1) {
      cout << a + i << endl;
    }
  }
  else {
    rep(i, k) {
      cout << a + i << endl;
    }
    rep(i, k) {
      cout << b - (k - 1) + i << endl;
    }
  }
  return 0;
}