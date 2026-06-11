#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;

  char s[h][w + 1];

  for (int i = 0; i < h; i++) cin >> s[i];

  int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
  int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int a = 0;
      if (s[i][j] == '#') continue;

      for (int k = 0; k < 8; k++) {
        if (i + dy[k] >= 0 && i + dy[k] < h && 
            j + dx[k] >= 0 && j + dx[k] < w) {
          if (s[i + dy[k]][j + dx[k]] == '#') a++;
        }
      }

      s[i][j] = '0' + a;
    }
  }

  for (int i = 0; i < h; i++) cout << s[i] << endl;
  return 0;
}
