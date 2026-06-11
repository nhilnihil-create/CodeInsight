#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int mx = max(a, max(b, c));
  int sum = a + b + c;
  if ((3 * mx) % 2 != sum % 2) mx++;
  int ans = (3 * mx - sum) / 2;
  cout << ans << endl;
  return 0;
}
