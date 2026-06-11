#include<bits/stdc++.h>
#define PI 3.141592653589
#define ll long long
using namespace std;

int main(){
  int h, w;
  cin >> h >> w;
  char s[h][w];
  for(int i=0; i<h; ++i){
    for(int j=0; j<w; ++j){
      cin >> s[i][j];
    }
  }

  const int dx[4] = {1, -1, 0,  0};
  const int dy[4] = {0,  0, 1, -1};

  int cnt = 0;
  bool flag = true;

  for(int i=0; i<h; ++i){
    for(int j=0; j<w; ++j){
      if(s[i][j] == '#'){
       bool can = false;
        for(int k=0; k<4; ++k){
          const int ni = i + dy[k];
          const int nj = j + dx[k];
          if(ni<0 || h<=ni) continue;
          if(nj<0 || w<=nj) continue;
          if(s[ni][nj] == '#') can = true;
        }
        if(can == false) flag = false;
      }
    }
  }
  if(flag) cout << "Yes" << endl;
  else cout << "No" << endl;


  return 0;
}