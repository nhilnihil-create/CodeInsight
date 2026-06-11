#include <bits/stdc++.h>

using namespace std;

template <typename T>
T num_div(T x) {
  T res = 0;
  for (T i = 1; i * i <= x; i++) {
    if (x % i == 0) {
      res++;
      if (i * i != x) res++;
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  for (int x = 1; x <= n; x += 2) {
    if (num_div(x) == 8) ans++;
  }
  cout << ans << '\n';
  return 0;
}