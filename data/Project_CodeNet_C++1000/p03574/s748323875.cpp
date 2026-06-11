

#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

char mat[52][52];

int main() {
  int h, w;
  cin >> h >> w;

  for (int i = 0; i < h + 2; i++) {
    mat[i][0] = '.';
    mat[i][w + 1] = '.';
  }
  for (int i = 0; i < w + 2; i++) {
    mat[0][i] = '.';
    mat[h + 1][i] = '.';
  }

  for (int i = 1; i < h + 1; i++) {
    for (int j = 1; j < w + 1; j++) {
      cin >> mat[i][j];
    }
  }

  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      int cnt = 0;
      if (mat[i][j] == '#') {
        cout << '#';
        continue;
      } else {
        rep(k, 8) {
          if (mat[i + dx[k]][j + dy[k]] == '#') {
            cnt++;
          }
        }
        cout << cnt;
      }
    }
    cout << endl;
  }
  return 0;
}
