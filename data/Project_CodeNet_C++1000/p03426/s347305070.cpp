#include <bits/stdc++.h>
using namespace std;
int main() {
  int A,H,W,D,L,R,Q;
  cin >> H >> W >> D;
  int dp[H*W+1],x[H*W+1],y[H*W+1];
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> A;
      x[A] = i;
      y[A] = j;
    }
  }
  for (int i = 1; i <= D; i++) {
    dp[i] = 0;
  }
  for (int i = D+1; i <= H*W; i++) {
    dp[i] = dp[i-D]+abs(x[i]-x[i-D])+abs(y[i]-y[i-D]);
  }
  for (cin >> Q; Q; Q--) {
    cin >> L >> R;
    cout << dp[R]-dp[L] << endl;
  }
}