#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, Z, W;
  cin >> N >> Z >> W;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  if (N == 1) {
    cout << abs(A[0] - W) << '\n';
  } else {
    cout << max(abs(A[N - 1] - W), abs(A[N - 2] - A[N - 1])) << '\n';
  }
  return 0;
}
