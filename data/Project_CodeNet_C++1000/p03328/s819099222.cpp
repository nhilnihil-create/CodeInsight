#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const ll mod = 1000000000 + 7;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int a, b;
  cin >> a >> b;
  int diff = b - a;
  int ans = 0;
  for (int i = 1; i < diff; i++) {
    ans += i;
  }
  ans -= a;
  cout << ans << endl;
}
