#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
 
  vector<int> t(N + 1), x(N + 1), y(N + 1);
  for (int i = 0; i < N; i++) {
    cin >> t[i + 1] >> x[i + 1] >> y[i + 1];
  }
 t[0]=0; x[0]=0; y[0]=0;
  bool can_move = true;
  for (int i = 0; i < N; i++) {
    int dt = t[i + 1] - t[i];
    int dxy = abs(x[i + 1] - x[i]) + abs(y[i + 1] - y[i]);  // 前回との移動値
    // 移動量を超えるか、偶数と奇数が一致しない場合は不可
    if (dxy > dt || dt % 2 != dxy % 2) can_move = false;
  }
 
  cout << (can_move ? "Yes" : "No") << endl;
}