#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  int ans = 0, y = 0;
  for (int i = 1; i <= n; i += 2) {
    y = 0;
    for (int j = 1; j <= i; j += 2)
      if (i % j == 0) y++;
    if (y == 8) ans++;
  }

  cout << ans << endl;
  return 0;
}
