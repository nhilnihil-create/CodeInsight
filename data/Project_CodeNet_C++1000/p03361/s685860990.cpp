#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> s(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) cin >> s[i][j];
  }
  string ans = "Yes";
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if(s[i][j] == '#') {
        if((0 < j && s[i][j-1] == '#') 
          || (j < w-1 && s[i][j+1] == '#') 
          || (0 < i && s[i-1][j] == '#') 
          || (i < h-1 && s[i+1][j] == '#')) {
          continue;
        }else {
          ans = "No";
          goto OUT;
        }
      }
    }
  }
  OUT:
  cout << ans;
}