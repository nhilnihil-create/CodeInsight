#include <bits/stdc++.h>

using namespace std;

const int md = (int) 1e9 + 7;

inline int add(int x, int y) {
  x += y;
  if (x >= md) x -= md;
  if (x < 0) x += md;
  return x;
}

inline int mul(int x, int y) {
  return (long long) x * y % md;
}

int power(int b, long long p) {
  int res = 1;
  while (p > 0) {
    if (p & 1) res = mul(res, b);
    b = mul(b, b);
    p >>= 1;
  }
  return res;
}

int inv(int x) {
  return power(x, md - 2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> pref(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = add(pref[i], inv(i + 1));
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ans = add(ans, mul(x, add(pref[i + 1] - 1, pref[n - i])));
  }
  for (int i = 0; i < n; i++) ans = mul(ans, i + 1);
  cout << ans << '\n';
  return 0;
}
