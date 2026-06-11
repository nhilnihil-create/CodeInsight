#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int L[N], R[N], res = INT_MAX; // L[i] is number of W from 0 to i. R[i] is number of E from i to N - 1.
  L[0] = S[0] == 'W' ? 1 : 0;
  R[N - 1] = S[N - 1] == 'E' ? 1 : 0;
  for (int i = 1; i < N; i++) {
    L[i] = L[i - 1] + (S[i] == 'W' ? 1 : 0);
  }
  for (int i = N - 2; i >= 0; i--) {
    R[i] = R[i + 1] + (S[i] == 'E' ? 1 : 0);
  }
  for (int i = 0; i < N; i++) {
    res = min(res, L[i] + R[i]);
  }
  cout << res - 1;
  return 0;
}