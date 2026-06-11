#include<iostream>
int main(void){
  //入力部
  int H,W;
  std::cin >> H >> W;
  std::string space[H*W];
  for (int i=0;i<H;i++){
    std::cin >> space[i];
  }
  //座標の差分
  const int dx[8] = {-1,0,1,-1,1,-1,0,1};
  const int dy[8] = {-1,-1,-1,0,0,1,1,1};
  //爆弾の個数の計測
  for (int i=0;i<H;i++){
    for (int j=0;j<W;j++){
      if (space[i][j] == '#') continue;
      int ct = 0;
      for (int d=0;d<8;d++){
        const int di = i + dy[d];
        const int dj = j + dx[d];
        if (di<0 || di>H) continue;
        if (dj<0 || dj>W) continue;
        if (space[di][dj] == '#'){
          ct++;
        }
      }
      space[i][j] = char(ct+'0');
    }
  }
  //表示
  for (int i=0;i<H;i++){
    for (int j=0;j<W;j++){
      std::cout << space[i][j];
    }
    std::cout << std::endl;
  }
  return 0;
}