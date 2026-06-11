#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int h,w;
  cin >> h >> w;
  char s[100][100];
  
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++)
      cin >> s[i][j];
  }
  
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if(s[i][j] == '#') {
        if(i-1 >= 0 & s[i-1][j] == '#') continue;
        else if(j-1 >= 0 & s[i][j-1] == '#') continue;
        else if(j+1 < w & s[i][j+1] == '#') continue;
        else if(i+1 < h & s[i+1][j] == '#') continue;
        else {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" << endl;
}
