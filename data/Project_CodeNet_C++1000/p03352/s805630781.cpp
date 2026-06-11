#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int X;
  cin >> X;
  int ans = 1;
  for (int i = 1; i <= 1000; i++) {
    for (int j = 2; j < 1000; j++) {
      double check_val = pow(i, j);
      if (check_val > X) continue;
      ans = max(ans, (int)pow(i, j));
    }
  }
  cout << ans << endl;
}
