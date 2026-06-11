#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  int cnt = 0;
  rep(i, a + 1) rep(j, b + 1) rep(k, c + 1) {
    int cost = 500 * i + 100 * j + 50 * k;
    if (cost == x) cnt++;
  }
  cout << cnt << endl;
  return 0;
}
