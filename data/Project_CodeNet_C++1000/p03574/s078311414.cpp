#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

int H, W;
using namespace std;

int hy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int wx[] = {1, 1, 0, -1, -1, -1, 0, 1};

//(x, y)がH*Wに収まっているかどうかを算判定
bool closed(int y, int x){
  bool flag = true;
  if(y<0 || H<=y)
    flag = false;
  if(x<0 || W<=x)
    flag = false;
  return flag;
}

int main(void){
  cin >> H >> W;
  string S[H];
  rep(i, H)
    cin >> S[i];
  //入力終了

  rep(i, H){
    rep(j, W){
      //爆弾マスは飛ばす
      if(S[i][j] == '#')
	continue;
      
      //周囲の#の数を数える
      int count = 0;

      rep(k, 8){
	//周囲の座標を計算
	int y = i+hy[k], x = j+wx[k];

	if(closed(y, x) ){
	  //爆弾マスを数える
	  if(S[y][x] == '#')
	    count++;
	}
      }// k roop
      //数値を数字に変換して代入
      S[i][j] = (char)(count+'0');

    }// j roop
  }// i roop

  //解答
  rep(i, H){
    rep(j, W)
      cout << S[i][j];
    cout << endl;
  }
  
  return 0;
}
