#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> vec(h);
  for (auto &v : vec)
    cin >> v;

  bool flag = true;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (vec[i][j] == '.')
        continue;
      bool flag2 = false;
      vector<int> dis = { -1, 1, 0, 0};
      vector<int> djs = { 0, 0, -1, 1};
      for (int k = 0; k < 4; ++k) {
        int i2 = i + dis[k];
        int j2 = j + djs[k];
        if (i2 < 0 || h <= i2 || j2 < 0 || w <= j2)
          continue;
        if (vec[i2][j2] == '#')
          flag2 = true;
      }
      if (flag2 == false)
        flag = false;
    }
  }

  cout << (flag ? "Yes" : "No") << endl;
}
