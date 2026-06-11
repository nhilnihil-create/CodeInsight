#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 100000000;
  for (int i = 0; i <= N; i++) {
    int X = i, Y = N - i;
    int K = 0, L = 0;
    while (X > 0) {
      K += X % 6;
      X /= 6;
    }
    while (Y > 0) {
      L += Y % 9;
      Y /= 9;
    }
    ans = min(ans, K + L);
  }
  cout << ans << endl;
}