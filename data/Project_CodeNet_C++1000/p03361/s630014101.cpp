#include <bits/stdc++.h>
using namespace std;
#define rep(i, seisu) for(int i = 0; i < (int)(seisu); i++)
typedef long long ll;


int main(){
  int h, w;
  cin >> h >> w;
  char paint[h][w];
  rep(i, h){
    rep(j, w){
      cin >> paint[i][j];
    }
  }
  int x[4] = {0, 0, -1, 1};
  int y[4] = {-1, 1, 0, 0};
  int check;
  int f = 0;
  rep(i, h){
    rep(j, w){
      check = 0;
      if (paint[i][j] == '#'){
        rep(k, 4){
          int nx = i + x[k], ny = j + y[k];
          if(nx >= 0 && ny >= 0 && nx <= h && ny <= w && paint[nx][ny] == '#'){
            check ++;
          }
        }
        if (check == 0) f = 1;
      }
      
    }
  }
  if (f == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  }