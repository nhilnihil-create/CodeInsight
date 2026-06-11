#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A[2][N];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int tmp = 0;
    int line = 0;
    for (int j = 0; j < N; j++) {
      tmp += A[line][j];

      if (i == j) {
        line++;
        tmp += A[line][j];
      }
    }
    ans = max(tmp, ans);
  }

  cout << ans << endl;

  return 0;
}
