#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int x = max({a, b, c});
  if ((3 * x) % 2 - (a + b + c) % 2 == 0) {
    cout << (3 * x - (a + b + c)) / 2 << endl;
  } else {
    cout << (3 * (x + 1) - (a + b + c)) / 2 << endl;
  }
  return 0;
}
