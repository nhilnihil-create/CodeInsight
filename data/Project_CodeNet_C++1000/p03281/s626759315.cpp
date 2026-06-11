#include <bits/stdc++.h>
using namespace std;

int f(int n) {
  int cnt = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      cnt++;
      if (i * i != n) cnt++;
    }
  }
  return cnt;
}

void solve() {
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 1; i <= N; i += 2)
    if (f(i) == 8) ans++;
  cout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}