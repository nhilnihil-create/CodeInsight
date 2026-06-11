#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, D, Q, N;
  cin >> H >> W >> D;
  N = H * W;
  vector X(N, 0), Y(N, 0), R(N, 0);
  for (int i = 0; i < H; i++) {
    for (int j = 0, a; j < W && cin >> a; j++) X.at(--a) = j, Y.at(a) = i;
  }
  for (int i = D; i < N; i++) {
    R.at(i) = R.at(i - D) + abs(X.at(i) - X.at(i - D)) + abs(Y.at(i) - Y.at(i - D));
  }
  cin >> Q;
  for (int l, r; cin >> l >> r;) cout << R.at(--r) - R.at(--l) << "\n";
}