#include "bits/stdc++.h"
using namespace std;
#define dump(x) cout << (x) << endl;
typedef int64_t Int;
Int mod = 1e9+7;

int main() {
  Int a, b;
  cin >> a >> b;
  Int k;
  cin >> k;
  while (k > 0) {
    b += a / 2;
    a /= 2;
    k--;
    if (k == 0) break;
    a += b / 2;
    b /= 2;
    k--;
  }
  cout << a << " " << b << endl;
  return 0;
}
