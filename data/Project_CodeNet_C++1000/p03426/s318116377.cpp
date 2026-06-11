#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, D;
  cin >> H >> W >> D;
  vector<int> X(H * W + 1), Y(H * W + 1);
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int A;
      cin >> A;
      X.at(A) = i;
      Y.at(A) = j;
    }
  }
  vector<int> d(H * W + 1);
  for (int i = 1; i <= H * W; i++) {
    if (i <= D) d.at(i) = 0;
    else d.at(i) = d.at(i - D) + abs(X.at(i) - X.at(i - D)) + abs(Y.at(i) - Y.at(i - D));
  }
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int L, R;
    cin >> L >> R;
    cout << d.at(R) - d.at(L) << endl;
  }
}