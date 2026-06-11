#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, num;
  cin >> h >> w;
  vector<string> s(h);
  for (int i = 0; i < h; i++) cin >> s.at(i);

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (s.at(i).at(j) == '.') {
        num = 0;
        if (i - 1 >= 0 && j - 1>= 0)
          if (s.at(i - 1).at(j - 1) == '#') num++;
        if (i - 1 >= 0)
          if (s.at(i - 1).at(j) == '#') num++;
        if (i - 1 >= 0 && j + 1 < w)
          if (s.at(i - 1).at(j + 1) == '#') num++;
        if (j - 1 >= 0)
          if (s.at(i).at(j - 1) == '#') num++;
        if (j + 1 < w)
          if (s.at(i).at(j + 1) == '#') num++;
        if (i + 1 < h && j - 1 >= 0)
          if (s.at(i + 1).at(j - 1) == '#') num++;
        if (i + 1 < h)
          if (s.at(i + 1).at(j) == '#') num++;
        if (i + 1 < h && j + 1 < w)
          if (s.at(i + 1).at(j + 1) == '#') num++;
        s.at(i).at(j) = num + '0';
      }
    }
  }
  for (int i = 0; i < h; i++) cout << s.at(i) << endl;
}