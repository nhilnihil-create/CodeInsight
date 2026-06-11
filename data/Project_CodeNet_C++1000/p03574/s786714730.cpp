#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w;
  scanf("%d %d", &h, &w);
  vector<vector<char>> s(h, vector<char>(w));
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) cin >> s[i][j];
  }
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(s[i][j] == '#') cout << '#';
      else {
          int bakudan = 0;
          if(0<i && 0<j && s[i-1][j-1] == '#') bakudan++;
          if(0<i && s[i-1][j] == '#') bakudan++;
          if(0<i && j<w-1 && s[i-1][j+1] == '#') bakudan++;
          if(0<j && s[i][j-1] == '#') bakudan++;
          if(j<w-1 && s[i][j+1] == '#') bakudan++;
          if(i<h-1 && 0<j && s[i+1][j-1] == '#') bakudan++;
          if(i<h-1 && s[i+1][j] == '#') bakudan++;
          if(i<h-1 && j<w-1 && s[i+1][j+1] == '#') bakudan++;
          cout << bakudan;
      }
    }
    cout << "\n";
  }
}