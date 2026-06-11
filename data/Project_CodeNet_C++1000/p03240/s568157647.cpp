#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> X(N), Y(N), H(N);
  for (int i = 0; i < N; i++) cin >> X.at(i) >> Y.at(i) >> H.at(i);
  for (int Cx = 0; Cx <= 100; Cx++) {
    bool B = false;
    for (int Cy = 0; Cy <= 100; Cy++) {
      int T;
      for (int i = 0; i < N; i++) {
        if (H.at(i) != 0) {
          T = abs(X.at(i) - Cx) + abs(Y.at(i) - Cy) + H.at(i);
          break;
        }
      }
      bool A = true;
      for (int i = 0; i < N; i++) {
        if (max(T - abs(X.at(i) - Cx) - abs(Y.at(i) - Cy), 0) != H.at(i)) {
          A = false;
          break;
        }
      }
      if (A) {
        cout << Cx << " " << Cy << " " << T << endl;
        B = true;
        break;
      }
    }
    if (B) break;
  }
}