#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int N, M, D;
  cin >> N >> M >> D;
  double ans;
  if (D == 0) ans = 1.0 * (M - 1) / N;
  else ans = 2.0 * (N - D) * (M - 1) / (N * N);
  cout << fixed << setprecision(20) << ans << endl;
}