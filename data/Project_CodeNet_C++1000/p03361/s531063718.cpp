#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  char s [H][W];
  for (int i=0;i<H;i++) {
    for (int j=0;j<W;j++) cin >> s[i][j];
  }
  int dx[4]={1,0,-1,0};
  int dy[4]={0,-1,0,1};
  bool can =true;
  for (int i=0;i<H;i++) {
    for (int j=0;j<W;j++) {
      bool found=false;
      if (s[i][j]=='#') {
        for (int k=0; k<4;k++) {
          int x=i+dx[k];
          int y=j+dy[k];
          if(0<=x&&x<H&&0<=y&&y<W&&s[x][y]=='#') found=true;
        }
        if (!found) {
          can=false;
          break;
        }
      }
    }
    if(!can) break;
  }
  if (can) cout<<"Yes"<<endl;
  else cout <<"No"<< endl;
}
