#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;

int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> paint(H+2, vector<char> (W+2, '.'));
  for(int i = 1; i <= H; i++){
     for(int j = 1; j <= W; j++){
      char s;
      cin >> s;
      paint[i][j] = s;
    }
  }
  
  bool x = true;
  for(int i = 1; i <= H; i++){
    for(int j = 1; j <= W; j++){
      if(paint[i][j] == '#'){
        if(paint[i-1][j]=='.' && paint[i+1][j]=='.' && paint[i][j-1]=='.' && paint[i][j+1]=='.'){
          x = false;
        }
      }
    }
  }
  
  if(x) cout << "Yes" << endl;
  else cout << "No" << endl;
}
     
      