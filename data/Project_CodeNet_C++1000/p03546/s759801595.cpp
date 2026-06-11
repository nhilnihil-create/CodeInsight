#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int H, W;
  cin >> H >> W;
  int A[10] = {}, c[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> c[i][j];
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int a;
      cin >> a;
      if (a >= 0) A[a]++;
    }
  }

  for (int k = 0; k < 10; k++) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
      }
    }
  }

  int ret = 0;
  for (int i = 0; i < 10; i++) {
    ret += c[i][1] * A[i];
  }
  cout << ret << endl;
}