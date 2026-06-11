#include <bits/stdc++.h>
using namespace std;

int main() {
  int i, j;
  
  int h, w;
  cin >> h >> w;
  
  vector<string> s(h);
  for (i = 0; i < h; i++) {
    cin >> s[i];
  }
  
  int is, ie, js, je;
  for (i = 0; i < h; i++) {
    is = -1; ie = 1;
    if (i == 0) {
      is = 0;
    }
    if (i == h - 1) {
      ie = 0;
    }
    for (j = 0; j < w; j++) {
      if (0 < j && j < w - 1) {
        js = -1; je = 1;
      } else if (j == 0) {
        js = 0; je = 1;
      } else {
        js = -1; je = 0;
      }
      
      if (s[i][j] == '.') {
        int count = 0;
        for (int ii = i + is; ii <= i + ie; ii++) {
          for (int jj = j + js; jj <= j + je; jj++) {
            if (s[ii][jj] == '#') {
              count++;
            }
          }
        }
        s[i].replace(j, 1, to_string(count));
      }
      
    }
  }
  
  for (i = 0; i < h; i++) {
    cout << s[i] << endl;
  }
}