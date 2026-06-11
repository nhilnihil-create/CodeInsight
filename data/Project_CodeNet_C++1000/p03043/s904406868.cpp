#include <bits/stdc++.h>
using namespace std;

int main() {
  double N;
  int K;
  cin >> N >> K;
  if(N >= K) {
    double ans = (N - K + 1) / N;
    for(int i = 1; i < K; i++) {
      double p = 1;
      int keep = i;
      while(keep < K) {
        p /= 2;
        keep *= 2;
      }
      ans += p / N;
    }
    cout << fixed << setprecision(10) << ans << endl;
  }
  else {
    double ans = 0;
    for(int i = 1; i <= N; i++) {
      double p = 1;
      int keep = i;
      while(keep < K) {
        p /= 2;
        keep *= 2;
      }
      ans += p / N;
    }
    cout << fixed << setprecision(10) << ans << endl;
  }
}