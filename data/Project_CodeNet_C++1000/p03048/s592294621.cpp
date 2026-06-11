#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll r, g, b, n, cnt = 0;
  cin >> r >> g >> b >> n;
  rep(i, n / r + 1) rep(j, n / g + 1) {
    if ((n - r * i - g * j) % b == 0 && 0 <= (n - r * i - g * j)) {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
