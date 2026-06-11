#include <bits/stdc++.h>
using namespace std;

int main() {
  double N, T, A;
  cin >> N >> T >> A;
  vector<double> H(N);
  for (int i = 0; i < N; i++) cin >> H.at(i);
  double mi = 1e9;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    double tmp = abs(A - (T - H.at(i) * 0.006));
    if (tmp < mi) mi = tmp, ans = i + 1;
  }
  cout << ans << "\n";
}