#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  if (N == 1) {
    cout << 1 << endl;
    return 0;
  }
  vector<vector<char>> S(N, vector<char>(N));
  rep(i, N) rep(j, N) cin >> S[i][j];

  int answer = 0;
  rep(i, N) {
    vector<vector<char>> T(N, vector<char>(N));
    const int A = 0;
    const int B = i;
    rep(y, N) {
      rep(x, N) { T[y][x] = S[(y + A) % N][(x + B) % N]; }
    }
    bool ok = true;
    rep(y, N) {
      rep(x, N) {
        if (T[y][x] != T[x][y]) {
          ok = false;
          break;
        }
      }
      if (!ok) break;
    }
    if (ok) answer++;
  }
  cout << answer * N << endl;
  return 0;
}