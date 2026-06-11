// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int H, W;
  cin >> H >> W;
  vector<vector<char>> s(H+2, vector<char>(W+2, '.'));
  for(int i = 1; i <= H; i++) {
    for(int j = 1; j <= W; j++) {
      cin >> s[i][j];
    }
  }

  int cnt = 0;
  for(int i = 1; i <= H; i++) {
    for(int j = 1; j <= W; j++) {
      if(s[i][j]     == '#' &&    // own color
         s[i][j - 1] != '#' &&    // left color
         s[i - 1][j] != '#' &&    // up color
         s[i][j + 1] != '#' &&    // right color
         s[i + 1][j] != '#') {    // down color
           cnt++;
      }
    }
  }

  if(cnt == 0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }

  return 0;
}
