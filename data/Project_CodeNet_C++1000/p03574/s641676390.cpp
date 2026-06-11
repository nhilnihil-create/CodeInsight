#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int h, w;
  cin >> h >> w;
  vector<string> ss(h);
  for (int i = 0; i < h; i++) cin >> ss[i];

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (ss[i][j] == '#') continue;

      int cnt = 0; 
      if (i != 0) {
        if (j != 0) cnt += (ss[i - 1][j - 1] == '#' ? 1 : 0);
        cnt += (ss[i - 1][j] == '#' ? 1 : 0); 
        if (j != w - 1) cnt += (ss[i - 1][j + 1] == '#' ? 1 : 0); 
      }

      if (j != 0) cnt += (ss[i][j - 1] == '#' ? 1 : 0); 
      if (j != w - 1) cnt += (ss[i][j + 1] == '#' ? 1 : 0); 

      if (i != h - 1) {
        if (j != 0) cnt += (ss[i + 1][j - 1] == '#' ? 1 : 0); 
        cnt += (ss[i + 1][j] == '#' ? 1 : 0); 
        if (j != w - 1) cnt += (ss[i + 1][j + 1] == '#' ? 1 : 0);
      }
      ss[i][j] = to_string(cnt)[0];
    }
  }

  for (int i = 0; i < h; i++) {
    cout << ss[i] << endl;
  }

  return 0;
}