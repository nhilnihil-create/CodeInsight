#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, c;
  ll k;
  cin >> a >> b >> c >> k;

  ll maxValue = 1000000000000000000;

  if (abs(a - b) > maxValue) {
    cout << "Unfair" << endl;
  } else {
    if (k % 2 == 0) {
      cout << (a - b) << endl;
    } else {
      cout << (b - a) << endl;
    }
  }
  return 0;
}
