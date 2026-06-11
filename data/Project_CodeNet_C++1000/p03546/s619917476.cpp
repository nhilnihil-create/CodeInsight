#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int H, W;
int c[10][10];
int A[200][200];

int main() {
  cin >> H >> W;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> c[i][j];
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A[i][j];
    }
  }

  int d[10];
  d[1] = 0;
  for (int i = 0; i < 10; i++) {
    if (i == 1)
      continue;

    int tmp[10];
    for (int j = 0; j < 10; j++)
      tmp[j] = INT_MAX;
    tmp[i] = 0;

    for (;;) {
      bool update = false;
      for (int j = 0; j < 10; j++) {
        for (int k = 0; k < 10; k++) {
          if (tmp[j] != INT_MAX && tmp[k] > tmp[j] + c[j][k]) {
            tmp[k] = tmp[j] + c[j][k];
            update = true;
          }
        }
      }
      if (!update)
        break;
    }
    d[i] = tmp[1];
  }

  int res = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (A[i][j] != -1) {
        res += d[A[i][j]];
      }
    }
  }
  cout << res << endl;

  return 0;
}
