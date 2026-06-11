#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> candle(N);
  for (int &e : candle) cin >> e;
  int L = candle[0];
  int R = candle[K-1];
  int ans = R-L+min(abs(L), abs(R));
  for (int i = 0; i < N-K; i++) {
    L = candle[i+1];
    R = candle[K+i];
    int a = R-L+min(abs(L),abs(R));
    ans = min(ans, a);
  }
  cout << ans << endl;
}