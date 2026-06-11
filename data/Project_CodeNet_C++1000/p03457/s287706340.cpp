#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(void){
  int N;
  cin >> N;
  int t[N+1], x[N+1], y[N+1];
  
  //初めは時刻0で原点にいる
  t[0] = 0, x[0] = 0, y[0] = 0;

  rep(i, N)
    cin >> t[i+1] >> x[i+1] >> y[i+1];
  //入力終了

  //現在地点
  int nowx = 0, nowy = 0;
  rep(i, N){
    //移動距離と制限時間
    int distance = abs(x[i+1]-nowx) + abs(y[i+1]-nowy);
    int time_limit = t[i+1]-t[i];
    //距離が制限時間よりも大きい
    if(distance > time_limit ){
      cout << "No" << endl;
      return 0;
    }
    else{
      //偶奇が一致していればたどり着ける
      if( ((distance^time_limit) & 1) == 0){
	//現在地点の更新
	nowx = x[i+1]; nowy = y[i+1];
	continue;
      }
      else{
	cout << "No" << endl;
	return 0;
      }
    }
  }

  //上のループを抜けていればOK
  cout << "Yes" << endl;
  
  return 0;
}
