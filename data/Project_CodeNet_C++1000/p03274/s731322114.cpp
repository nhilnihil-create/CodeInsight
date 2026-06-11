#include <iostream>
#include <cmath>

using namespace std;

int main(void){
  int i;
  int N, K;
  cin >> N >> K;
  long long x[N];
  for(i=0; i<N; i++)
    cin >> x[i];
  //入力終わり

  long long tmp;
  long long ans = 1000000000000000000; //10^18ぐらいで適当に初期化
  int l, r;
  //左端を固定して全探索
  for(l = 0; l<=N-K; l++ ){
    r = l + K - 1;
    //min(左行ってから右，右行ってから左)
    tmp = min(abs(x[l] )+abs(x[r]-x[l] ),
	      abs(x[r] )+abs(x[r]-x[l] ) );
    //最初値の更新
    if(tmp < ans)
      ans = tmp;
  }

  cout << ans << endl;
    
  return 0;
}
