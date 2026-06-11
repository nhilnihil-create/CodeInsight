#include <iostream>
#include <vector>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
  int H, W, D, Q;
  cin >> H >> W >> D;
  vector<vector<int>> A(H, vector<int>(W));
  rep(i, H) rep(j, W) cin >> A[i][j];
  cin >> Q;
  vector<int> L(Q), R(Q);
  rep(i, Q) cin >> L[i] >> R[i];
  
  vector<int> Z(H * W + 1);
  rep(i, H) rep(j, W) Z[A[i][j]] = i * W + j;
  vector<int> S(H * W + 1, 0);
  for (int i = D + 1; i < H * W + 1; ++i) {
    int x = Z[i - D] / W;
    int y = Z[i - D] % W;
    int X = Z[i] / W;
    int Y = Z[i] % W;
    S[i] = S[i - D] + abs(x - X) + abs(y - Y);
  }
  
  for (int i = 0; i < Q; ++i) cout << S[R[i]] - S[L[i]] << endl;
  return 0;
}