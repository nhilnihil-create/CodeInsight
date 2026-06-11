#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int n;

int rec(ll x, bool f7, bool f5, bool f3) {
  if (x > n) return 0;

  int res = 0;
  res += rec(10 * x + 7, true, f5, f3);
  res += rec(10 * x + 5, f7, true, f3);
  res += rec(10 * x + 3, f7, f5, true);
  res += (f7 && f5 && f3);
  return res;
}

int main() {
  cin >> n;
  cout << rec(0, false, false, false) << endl;
  return 0;
}
