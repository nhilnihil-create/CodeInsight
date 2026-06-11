#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, T, A;
  cin >> N >> T >> A;
  double memo = ((T - A) * 1000 + 0.0) / 6;
  int ans;
  double best = 1000000000000;
  for (int i = 0; i < N; i++) {
    int H;
    double memo2;
    cin >> H;
    if (H > memo) {
      memo2 = H - memo;
    }
    else {
      memo2 = memo - H;
    }
    if (best > memo2) {
      best = memo2;
      ans = i + 1;
    }
  }
  cout << ans << endl;   
}