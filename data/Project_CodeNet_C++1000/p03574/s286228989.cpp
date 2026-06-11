#include <iostream>

using namespace std;

int main() {
  int h, w;
  string s[50];
  cin >> h >> w;
  for (int i = 0; i < h; i++) {
    cin >> s[i];
  }

  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      if (s[y][x] == '#') {
        continue;
      }
      if (s[y][x] == '.') {
        s[y][x] = '0';
      }

      // y=-1
      if (y > 0 && x > 0 && s[y - 1][x - 1] == '#') {
        s[y][x]++;
      }
      if (y > 0 && s[y - 1][x] == '#') {
        s[y][x]++;
      }
      if (y > 0 && x < w && s[y - 1][x + 1] == '#') {
        s[y][x]++;
      }

      // y=0
      if (x > 0 && s[y][x - 1] == '#') {
        s[y][x]++;
      }
      if (x < w && s[y][x + 1] == '#') {
        s[y][x]++;
      }

      // y=1
      if (y < h && x > 0 && s[y + 1][x - 1] == '#') {
        s[y][x]++;
      }
      if (y < h && s[y + 1][x] == '#') {
        s[y][x]++;
      }
      if (y < h && x < w && s[y + 1][x + 1] == '#') {
        s[y][x]++;
      }
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << s[i][j];
    }
    cout << endl;
  }
  return 0;
}
