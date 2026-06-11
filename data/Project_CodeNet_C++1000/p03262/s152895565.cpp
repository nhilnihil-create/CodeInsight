#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N, X;
  cin >> N >> X;
  vector<int> x(N);
  vector<int> dif(N);
  for (int i = 0; i < N; i++) {
    cin >> x[i];
    dif[i] = abs(x[i] - X);
  }
  int ans = dif[0];
  for (int i = 1; i < N; i++) {
    ans = __gcd(ans, dif[i]);
  }
  if (N == 1) {
    cout << dif[0] << endl;
  } else {
    cout << ans << endl;
  }
}
