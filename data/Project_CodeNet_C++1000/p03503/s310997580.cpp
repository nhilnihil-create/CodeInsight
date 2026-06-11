#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main(){
  int N;
  cin >> N;
  bool F[N][10];
  rep(i, N)
    rep(j, 10)
    cin >> F[i][j];
  int P[N][11];
  rep(i, N)
    rep(j, 11)
    cin >> P[i][j];
  //入力終わり

  int count[N];
      
  int sum, max = -1000000000;
  for(int bit=1; bit<(1<<10); bit++){
    //sumとcountの初期化
    sum = 0;
    rep(i, N)
      count[i] = 0;

    //10個の時間帯について
    rep(i, 10){
      //それぞれの時間帯で店を開けるとき
      if(bit & (1<<i) ){
	//店jも開けていれば
	rep(j, N){
	  if(F[j][i] == true)
	    //店jのカウント
	    count[j]++;
	}// j roop
      }// if
    } //i roop

    //利益の計算
    rep(i, N)
      sum += P[i][count[i] ];

    //最大値の更新
    if(max < sum)
      max = sum;

  } //bit roop

  //解答
  cout << max << endl;

  return 0;
}
