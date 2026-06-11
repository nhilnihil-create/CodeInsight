#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  if(N == 1) {
    cout << 1 << endl;
    return 0;
  }
  else {
    long double T, A;
    cin >> T >> A;
    long double H;
    cin >> H;
    long double t = T - H * 0.006;
    long double min;
    if(t > A) {
      min = t - A;
    }
    else {
      min = A - t;
    }
    int ans = 1;
    for(int i = 1; i < N; i++) {
      cin >> H;
      long double t = T - H * 0.006;
      long double d;
      if(t > A) {
        d = t - A;
      }
      else {
        d = A - t;
      }
      if(min > d) {
        min = d;
        ans = i + 1;
      }
    }
    cout << ans << endl;
    return 0;
  }
}