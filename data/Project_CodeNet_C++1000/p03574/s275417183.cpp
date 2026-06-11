#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int h, w;
  cin >> h >> w;
  string s = "";
  rep(i, h) {
    string j;
    cin >> j;
    s += j;
  }
  rep(i, h*w) {
    int x = 0;
    if (s.at(i) == '#') {
      cout << '#';
    } else {
      int hi = i / w, wi = i % w;
      if (hi > 0 && wi > 0 && s.at(i-w-1) == '#') x++;
      if (hi > 0 && s.at(i-w) == '#') x++;
      if (hi > 0 && wi < (w-1) && s.at(i-w+1) == '#') x++;
      if (wi > 0 && s.at(i-1) == '#') x++;
      //if (s.at(i) == '#') x++;
      if (wi < (w-1) && s.at(i+1) == '#') x++;
      if (hi < (h-1) && wi > 0 && s.at(i+w-1) == '#') x++;
      if (hi < (h-1) && s.at(i+w) == '#') x++;
      if (hi < (h-1) && wi < (w-1) && s.at(i+w+1) == '#') x++;
      cout << x;
    }
    if (i % w == (w - 1)) {
      cout << endl;
    }
  }
}