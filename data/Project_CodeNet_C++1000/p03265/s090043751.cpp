#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x = c - a, y = d - b;
  printf("%d %d %d %d\n", c - y, d + x, a - y, b + x);
  return 0;
}
