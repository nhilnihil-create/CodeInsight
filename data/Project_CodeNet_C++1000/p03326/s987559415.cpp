#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N,M,answer=0;
  cin >> N >> M;
  long long x[N],y[N],z[N],X[N];
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i] >> z[i];
  }
  for (int n = 0; n < 8; n++) {
    for (int i = 0; i < N; i++) {
      int m = n;
      if (m%2) {
        X[i] = x[i];
      } else {
        X[i] = -x[i];
      }
      m /= 2;
      if (m%2) {
        X[i] += y[i];
      } else {
        X[i] -= y[i];
      }
      m /= 2;
      if (m%2) {
        X[i] += z[i];
      } else {
        X[i] -= z[i];
      }
    }
    long long Y = 0;
    sort(X,X+N,greater<long long>());
    for (int i = 0; i < M; i++) {
      Y += X[i];
    }
    answer = max(answer,Y);
  }
  cout << answer;
}