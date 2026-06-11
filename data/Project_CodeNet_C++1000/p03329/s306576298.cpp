#include <iostream>

using namespace std;

//n^rを返す
int power(int n, int r){
  int ans = 1;
  for(int i=0; i<r; i++)
    ans *= n;
  return ans;
}


int main(void){
  int N;
  cin >> N;
  //入力終わり

  //6と9の指数の最大
  int six_max  = 7;
  int nine_max = 6;

  //dp配列の初期化
  int dp[N+1];
  for(int i=0; i<=N; i++)
    dp[i] = N;
  dp[0] = 0;

  //今いる場所，次見る場所
  int now, next;
  for(now=0; now<N; now++){
    //nowから6の冪乗だけ先を見る
    for(int j=1; j<six_max; j++){
      next = now+power(6, j);
      //nextがはみ出していない
      if(next <= N)
	//nextの現状か，nowから1つ増やすかの選択
	dp[next] = min(dp[next], dp[now]+1);
    }
    //6の冪乗のときと同じ
    for(int j=1; j<nine_max; j++){
      next = now+power(9, j);
      if(next <= N)
	dp[next] = min(dp[next], dp[now]+1);
    }
    //now+1の更新
    dp[now+1] = min(dp[now+1], dp[now]+1);
  }

    cout << dp[N] << endl;
  
  return 0;
}
