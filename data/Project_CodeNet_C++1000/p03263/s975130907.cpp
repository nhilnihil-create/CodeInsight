#include <iostream>
#include <tuple>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> A(H, vector<int>(W));
  rep(i, H) rep(j, W) cin >> A[i][j];

  int N = 0;
  vector<tuple<int, int, int, int>> STEP;
  rep(i, H) {
    rep(j, W) {
      if (A[i][j] % 2) {
        int ni = i + 1;
        int nj = j + 1;
        if (nj < W && A[i][nj] % 2) {
          STEP.emplace_back(i, j, i, nj);
          A[i][nj]++;
          A[i][j]--;
          N++;
        } else if (ni < H && A[ni][j] % 2) {
          STEP.emplace_back(i, j, ni, j);
          A[ni][j]++;
          A[i][j]--;
          N++;
        } else if (nj < W) {
          STEP.emplace_back(i, j, i, nj);
          A[i][nj]++;
          A[i][j]--;
          N++;
        } else if (ni < H) {
          STEP.emplace_back(i, j, ni, j);
          A[ni][j]++;
          A[i][j]--;
          N++;
        }
      }
    }
  }

  cout << N << endl;
  rep(i, N) {
    int y, x, ny, nx;
    tie(y, x, ny, nx) = STEP[i];
    cout << y + 1 << " " << x + 1 << " " << ny + 1 << " " << nx + 1 << endl;
  }
  return 0;
}