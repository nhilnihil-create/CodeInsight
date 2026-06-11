#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int a, b, k;

int main() {
  cin >> a >> b >> k;
  rep (i, k) {
    if (a + i <= b) cout << a + i << endl;
  }
  rep (i, k) {
    if (a - b + 2 * k < i + 2) cout << b - k + i + 1 << endl;
  }
  return 0;
}
