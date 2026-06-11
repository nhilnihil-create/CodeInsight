#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> vec(h);
  for (auto &v : vec)
    cin >> v;

  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (vec[i][j] == '.')
        vec[i][j] = '0';
      if (vec[i][j] != '#')
        continue;
      for (int k = 0; k < 3; ++k) {
        for (int l = 0; l < 3; ++l) {
          if (k == 1 && l == 1)
            continue;
          int x = i - 1 + k;
          int y = j - 1 + l;
          if (x < 0 || h <= x || y < 0 || w <= y || vec[x][y] == '#')
            continue;
          if (vec[x][y] == '.')
            vec[x][y] = '1';
          else
            vec[x][y] = char(int(vec[x][y] - '0' + 1) + '0');
        }
      }
    }
  }

  for (auto &v : vec)
    cout << v << endl;
}
