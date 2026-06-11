#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main(void){
  int N;
  cin >> N;
  int C[N-1], S[N-1], F[N-1];
  rep(i, N-1)
    cin >> C[i] >> S[i] >> F[i];
  //入力終わり

  //各駅スタート
  rep(i, N-1){
    int now = i;
    //時刻を更新していく
    int time = S[i]+C[i];
    //駅iから先を見ていく
    for(int j=i+1; j<N-1; j++){
      //到着時刻が，駅jの最初の出発時刻より先だったとき
      if(time < S[j])
	//最初の出発時刻まで待ってから出発
	time += (S[j] - time) + C[j];
      //到着時刻が，駅jの最初の出発時刻より後だったとき
      else{
	//待ち時間なし
	if(time % F[j] == 0)
	  time += C[j];
	//待ち時間あり
	else
	  time += F[j] - (time%F[j]) + C[j];
      }
    }
    //解答
    cout << time << endl;
  }

  
  cout << 0 << endl;

  return 0;
}
