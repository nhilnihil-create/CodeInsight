#include <bits/stdc++.h>
using namespace std;
int main() {
  int N,W,Z,answer=0;
  cin >> N >> Z >> W;
  int a[N], X[N], Y[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  X[N-1] = a[N-1];
  Y[N-1] = W;
  for (int i = N-2; i+1; i--) {
    X[i] = a[i];
    Y[i] = a[N-1];
    for (int j = i+1; j < N-1; j++) {
      if (abs(X[j]-Y[j]) < abs(X[i]-Y[i])) {
        X[i] = Y[j];
        Y[i] = X[j];
      }
    }
  }
  for (int i = 0; i < N; i++) {
    answer = max(answer,abs(X[i]-Y[i]));
  }
  cout << answer;
}