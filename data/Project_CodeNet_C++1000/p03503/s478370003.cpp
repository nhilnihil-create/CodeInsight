#include<bits/stdc++.h>
using namespace std;
int main () {
  int N;
  cin >> N;
  int F[110][10];
  for (int i = 0; i < N; i ++) {
    for (int j = 0; j < 10; j ++) {
      cin >> F[i][j];
    }
  }
  int C[110][11];
  for (int i = 0; i < N; i ++) {
    for (int j = 0; j < 11; j ++) {
      cin >> C[i][j];
    }
  }
  int ans = 1e9 + 7;
  ans *= -1;
  int f[10];
  for (int i = 1; i < 1 << 10; i ++) {
    int i_ = i;
    for (int j = 0; j < 10; j ++) {
      f[j] = i_ % 2;
      i_ /= 2;
    }
    int kj = 0;
    for (int j = 0; j < N; j ++) {
      int al = 0;
      for (int k = 0; k < 10; k ++) {
        al += f[k] * F[j][k];
      }
      kj += C[j][al];
    }
    if (ans < kj) {
      ans = kj;
      //cout << i << ' ' << kj << endl;
    }
  }
  cout << ans << endl;
}

