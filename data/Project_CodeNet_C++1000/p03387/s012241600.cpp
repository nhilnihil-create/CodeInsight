#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if (a < b) swap(a, b);
  if (a < c) swap(a, c);
  if (b < c) swap(b, c);
  int ans = 0;
  ans += a - b;
  ans += (b - c) / 2;
  if ((b - c) % 2 != 0) ans += 2;
  cout << ans << endl;
  return 0;
}
