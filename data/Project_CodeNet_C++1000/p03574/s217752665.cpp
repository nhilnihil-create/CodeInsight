#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int h,w;
  cin >> h >> w;
  char c[h][w];
  rep(i,h){
    rep(j,w){
      cin >> c[i][j];
    }
  }
  int x[8]={1,1,0,-1,-1,-1,0,1};
  int y[8]={0,1,1,1,0,-1,-1,-1};
  rep(i,h){
    rep(j,w){
      if(c[i][j]!='#'){
        char sum='0';
        rep(k,8){
          int xx=x[k]+j;
          int yy=y[k]+i;
          if(xx>=w||xx<0||yy>=h||yy<0){
            continue;
          }
          if(c[yy][xx]=='#'){
            sum++;
          }
        }
        c[i][j]=sum;
      }
    }
  }
  rep(i,h){
    rep(j,w){
      cout << c[i][j];
    }
    cout << endl;
  }
}