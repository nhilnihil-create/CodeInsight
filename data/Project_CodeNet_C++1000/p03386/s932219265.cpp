#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  if (b - a + 1 < 2 * k) {
    for (int i = a; i <= b; ++i) cout << i << endl;
  } else {
    rep(i, k) cout << a + i << endl;
    rep(i, k) cout << b - k + 1 + i << endl;
  }
  return 0;
}