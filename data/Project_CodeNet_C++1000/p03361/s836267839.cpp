#include <iostream>
#include <string>
using namespace std;

int H,W;

int main(){
  cin >> H >> W;
  string board[H*W];
  for(int i=0; i<H; i++) cin >> board[i];
  const int dx[4] = {1,0,-1,0};
  const int dy[4] = {0,1,0,-1};
  
  for(int y=0; y<H; y++){
    for(int x=0; x<W; x++){
      if(board[y][x]=='.') continue;
      bool flg = false;
      for(int k=0; k<4; k++){
        if(y+dy[k]<0 || y+dy[k]>=H || x+dx[k]<0 || x+dx[k]>=W) continue;
        if(board[y+dy[k]][x+dx[k]] == '#') flg = true;
      }
      if(!flg){
        cout << "No" << endl;
        return 0;
      }      
    }
  }
  cout << "Yes" << endl;
  return 0;
}
