#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  int ans = m * 1900 + (n - m) * 100;
  while (m--) {
    ans *= 2;
  }
  cout << ans;
  return 0;
}