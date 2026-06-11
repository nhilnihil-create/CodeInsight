#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int x;
  cin >> x;
  if (x == 1) {
    cout << 1 << endl;
    return 0;
  }

  int ans = 1;
  for (int b = 2; b < x; b++) {
    int p = 2;
    while (pow(b, p) <= x) p++;
    if (2 <= p - 1) ans = max(ans, int(pow(b, p - 1)));
  }
  cout << ans << endl;
  return 0;
}
