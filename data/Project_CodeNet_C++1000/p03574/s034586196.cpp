#include <bits/stdc++.h>
using namespace std;
int main() {
  int H,W;
  cin >> H >> W;
  string S[H];
  for (int i = 0; i < H; i++) {
    cin >> S[i];
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0, bombs = 0; j < W; j++, bombs = 0) {
      if (S[i][j] != '#') {
        bombs += i && j && S[i-1][j-1] == '#';
        bombs += i && S[i-1][j] == '#';
        bombs += i && j+1 < W && S[i-1][j+1] == '#';
        bombs += j && S[i][j-1] == '#';
        bombs += j+1 < W && S[i][j+1] == '#';
        bombs += i+1 < H && j && S[i+1][j-1] == '#';
        bombs += i+1 < H && S[i+1][j] == '#';
        bombs += i+1 < H && j+1 < W && S[i+1][j+1] == '#';
        S[i][j] = '0'+bombs;
      }
      cout << S[i][j];
    }
    cout << '\n';
  }
}