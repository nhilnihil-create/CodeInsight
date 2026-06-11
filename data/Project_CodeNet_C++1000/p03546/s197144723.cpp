#include <bits/stdc++.h>
#define N 10
using namespace std;
int main() {
  long long c[N][N], H, W, A, answer = 0;
  cin >> H >> W;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> c[i][j];
    }
  }
  long long C[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      C[i][j] = c[i][j];
    }
  }
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        C[i][j] = min(C[i][j],C[i][k]+C[k][j]);
      }
    }
  }
  while (H--) {
    for (int w = 0; w < W; w++) {
      cin >> A;
      if (A != -1) {
        long long cost = C[A][1];
        for (int i = 0; i < N; i++) {
          cost = min(cost,C[A][i]+C[i][1]);
        }
        answer += cost;
      }
    }
  }
  cout << answer;
}