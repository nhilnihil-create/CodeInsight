#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  double ans = 0;
  for (int64_t i = 1; i <= N; i++) {
    int64_t memo = i;
    double memo2 = 1.0 / N;
    while (memo < K) {
      memo *= 2;
      memo2 *= 0.5;
    }
    ans += memo2;
  }
  cout << fixed << setprecision(16);
  
  cout << ans << endl;
}