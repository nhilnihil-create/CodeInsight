#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int A, B;
  cin >> A >> B;

  vector<vector<char>> answer(100, vector<char>(100));
  rep(i, 100) {
    rep(j, 100) {
      if (i < 50)
        answer[i][j] = '#';
      else
        answer[i][j] = '.';
    }
  }

  int out = 0;
  while (out / 2 != (A - 1)) {
    int y = (out / 100) * 2;
    int x = out % 100 + y % 2;
    answer[y][x] = '.';
    out += 2;
  }

  out = 0;
  while (out / 2 != (B - 1)) {
    int y = 51 + out / 100 * 2;
    int x = out % 100 + y % 2;
    answer[y][x] = '#';
    out += 2;
  }

  cout << "100 100" << endl;
  rep(i, 100) {
    rep(j, 100) { cout << answer[i][j]; }
    cout << endl;
  }
  return 0;
}