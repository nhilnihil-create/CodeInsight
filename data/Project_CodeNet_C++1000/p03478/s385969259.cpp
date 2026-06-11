#include <iostream>

using namespace std;

int main(void){
  int N, A, B;
  cin >> N >> A >> B;
  //入力終了

  int ans = 0;
  
  //1以上N以下の全探索
  for(int n=1; n<=N; n++){
    int tmp = n;
    int sum = 0;
    //各桁の和を計算
    while(tmp != 0){
      sum += tmp%10;
      tmp /= 10;
    }
    //各桁の和がA以上B以下
    if(A<=sum && sum<=B)
      ans += n;
  }

  //解答
  cout << ans << endl;

  return 0;
}
