#include <bits/stdc++.h>

using namespace std;

int main() {
  int H, W, D;
  cin >> H >> W >> D;
  vector<pair<int, int>> A(H * W + D + 1);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int a;
      cin >> a;
      A[a] = {i, j};
    }
  }
  int Q;
  cin >> Q;
  vector<int> L(Q), R(Q);
  for (int i = 0; i < Q; i++) {
    cin >> L[i] >> R[i];
  }

  vector<long long> C(H * W + D + 1);
  for (int i = 0; i <= H * W; i++) {
    C[i + D] = abs(A[i].first - A[i + D].first) + abs(A[i].second - A[i + D].second) + C[i];
  }
  for (int i = 0; i < Q; i++) {
    cout << C[R[i]] - C[L[i]] << endl;
  }

  return 0;
}
/* vim:set fdm=marker: */
