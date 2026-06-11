#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int h, w;
  string s;
  cin >> h >> w;
  vector<vector<char>> v(h, vector<char>(w));
  vector<vector<int>> vv(h+2, vector<int>(w+2));
  for(int i=0; i<h; i++) {
    cin >> s;
    for(int j=0; j<w; j++) {
      v[i][j] = s[j];
      if(s[j]=='#') {
        vv[i][j] += 1;
        vv[i][j+1] += 1;
        vv[i][j+2] += 1;
        vv[i+1][j] += 1;
        vv[i+1][j+2] += 1;
        vv[i+2][j] += 1;
        vv[i+2][j+1] += 1;
        vv[i+2][j+2] += 1;
      }
    }
  }
  
  for(int i=1; i<h+1; i++) {
    for(int j=1; j<w+1; j++) {
      if(v[i-1][j-1]=='#') cout << v[i-1][j-1];
      else cout << vv[i][j];
      if(j==w) cout << endl;
    }
  }
  return 0;
}