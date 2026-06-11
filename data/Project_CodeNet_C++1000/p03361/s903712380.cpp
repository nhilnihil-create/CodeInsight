#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i, n)for(int i=0; i<n; i++)

int hy[] = {0, 1, 0, -1};
int wx[] = {1, 0, -1, 0};

int H, W;

bool closed(int x, int y){
  bool flag = true;
  if(x<0 || W<=x)
    flag = false;
  if(y<0 || H<=y)
    flag = false;
  return flag;
}


int main(){
  cin >> H >> W;
  char s[H][W];
  rep(i, H)
    rep(j, W)
    cin >> s[i][j];
  //入力終了

  bool flag;
  rep(i, H){
    rep(j, W){
      //.は飛ばす
      if(s[i][j] == '.')
	continue;
      flag = false;
      //4方向の判定
      rep(k, 4){
	//近傍の点がマス目におさまっているか
	if(closed(j+wx[k], i+hy[k]) ){
	  if(s[i+hy[k] ][j+wx[k] ] == '#'){
	    flag = true;
	  }
	}
      } // k
  
      //孤立した#があれば終了
      if(!flag){
	cout << "No" << endl;
	return 0;
      }
    } //j
  } // i

  //上のループを抜ければOK
  cout << "Yes" << endl;

  return 0;
}
