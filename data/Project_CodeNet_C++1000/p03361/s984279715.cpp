#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w; cin >> h >> w;
  vector<vector<char>> s(h,vector<char>(w));
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      cin >> s[i][j];
    }
  }
  for(int i=0; i<h; i++) {
    for(int j=0; j<w; j++) {
      if((s[i][j]=='#')
         &&(i==0||s[i-1][j]=='.')
         &&(i==h-1||s[i+1][j]=='.')
         &&(j==0||s[i][j-1]=='.')
         &&(j==w-1||s[i][j+1]=='.')) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}