#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, T;
  cin >> N >> T;
  vector<int> c(N), t(N);
  for (int i = 0; i < N; i++) cin >> c[i] >> t[i];
  int ans = 10000;
  for (int i = 0; i < N; i++) {
    if (T >= t[i]) {
      if (ans > c[i]) ans = c[i];
    }
  }
  if (ans != 10000) cout << ans << endl;
  else cout << "TLE" << endl;
}
