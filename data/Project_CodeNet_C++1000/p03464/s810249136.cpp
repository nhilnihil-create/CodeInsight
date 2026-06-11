#include <bits/stdc++.h>
using namespace std;

int main() {
  int K; cin >> K;
  vector<int> A(K);
  for (int i = 0; i < K; i++) cin >> A.at(i);
  reverse(A.begin(), A.end());
  long long N = 2, M = 2;
  for (int i = 0; i < K; i++) {
    // N から M の間に A[i] の倍数があるか
    int r = (N % A.at(i)) ? (N % A.at(i)) : A.at(i);
    if (M < N + A.at(i) - r) { cout << -1 << endl; return 0; }
    N = ((N + A.at(i) - 1) / A.at(i)) * A.at(i);
    M = (M / A.at(i)) * A.at(i) + A.at(i) - 1;
  }
  cout << N << " " << M << endl;
}