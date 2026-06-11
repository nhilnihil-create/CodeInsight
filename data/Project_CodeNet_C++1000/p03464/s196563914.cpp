#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int K;
  cin >> K;
  vector<int64_t> A(K);
  for (int i = 0; i < K; i++) {
    cin >> A[i];
  }
  reverse(A.begin(), A.end());
  int64_t lo = 2, hi = 2;
  for (int i = 0; i < K; i++) {
    if (lo % A[i] != 0 && lo / A[i] == hi / A[i]) {
      cout << -1 << '\n';
      return 0;
    }
    lo = (lo + A[i] - 1) / A[i] * A[i];
    hi = hi / A[i] * A[i] + A[i] - 1;
  }
  cout << lo << ' ' << hi << '\n';
  return 0;
}
