#include <bits/stdc++.h>
using namespace std;
int main() {
  int H,W;
  cin >> H >> W;
  string s[H];
  for (int i = 0; i < H; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0, n = 0; j < W; j++, n = 0) {
      if (s[i][j] == '#') {
        n += i && s[i-1][j] == '.';
      	n += j && s[i][j-1] == '.';
      	n += i+1 < H && s[i+1][j] == '.';
        n += j+1 < W && s[i][j+1] == '.';
        if (n == 4) {
          cout << "No";
          return 0;
        }
      }
    }
  }
  cout << "Yes";
}