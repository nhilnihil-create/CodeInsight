#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int h, w;
  cin >> h >> w;

  vector<string> v(h);
  for (int i = 0; i < h; i++) {
    cin >> v.at(i);
  }

  vector<int> dx{ -1, -1, -1,  0, 0,  1, 1, 1 };
  vector<int> dy{ -1,  0,  1, -1, 1, -1, 0, 1 };

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (v.at(i).at(j) == '.') {
        int num = 0;
        for (int k = 0; k < 8; k++) {
          int x = i - dx.at(k);
          int y = j - dy.at(k);
          if (x >= 0 && x < h && y >= 0 && y < w) {
            if (v.at(x).at(y) == '#') {
              num++;
            }
          }
        }
        cout << num;
      } else {
        cout << '#';
      }
    }
    cout << endl;
  }

  return 0;
}