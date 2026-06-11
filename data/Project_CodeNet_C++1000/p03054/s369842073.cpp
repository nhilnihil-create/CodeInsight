#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int H, W, N;
  cin >> H >> W >> N;
  int r, c;
  cin >> r >> c;
  string S, T;
  cin >> S >> T;

  int left = 1;
  int right = W;
  int up = 1;
  int down = H;
  if (S[N - 1] == 'L') ++left;
  if (S[N - 1] == 'R') --right;
  if (S[N - 1] == 'U') ++up;
  if (S[N - 1] == 'D') --down;
  for (int i = N - 2; i >= 0; --i) {
    if (T[i] == 'L') right = min(right + 1, W);
    if (T[i] == 'R') left = max(1, left - 1);
    if (T[i] == 'U') down = min(down + 1, H);
    if (T[i] == 'D') up = max(1, up - 1);

    if (S[i] == 'R') --right;
    if (S[i] == 'L') ++left;
    if (S[i] == 'D') --down;
    if (S[i] == 'U') ++up;

    if (left > right || up > down) {
      cout << "NO" << endl;
      return 0;
    }
  }

  if ((left <= c && c <= right) && (up <= r && r <= down)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}