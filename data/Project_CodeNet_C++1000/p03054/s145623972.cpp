#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W, N; cin >> H >> W >> N;
  int sr, sc; cin >> sr >> sc;
  string S, T; cin >> S >> T;

  int left = 1, right = W;
  if (S.at(N-1) == 'L') left++;
  if (S.at(N-1) == 'R') right--;
  for (int i = N-2; i >= 0; i--) {
    if (T.at(i) == 'L') right = min(right + 1, W);
    if (T.at(i) == 'R') left = max(1, left - 1);
    if (S.at(i) == 'L') left++;
    if (S.at(i) == 'R') right--;
    if (left > right) { cout << "NO" << endl; return 0; }
  }
  if (sc < left || sc > right) { cout << "NO" << endl; return 0; }

  int up = 1, down = H;
  if (S.at(N-1) == 'U') up++;
  if (S.at(N-1) == 'D') down--;
  for (int i = N-2; i >= 0; i--) {
    if (T.at(i) == 'U') down = min(down + 1, H);
    if (T.at(i) == 'D') up = max(1, up - 1);
    if (S.at(i) == 'U') up++;
    if (S.at(i) == 'D') down--;
    if (up > down) { cout << "NO" << endl; return 0; }
  }
  if (sr < up || sr > down) { cout << "NO" << endl; return 0; }
  cout << "YES" << endl;
}