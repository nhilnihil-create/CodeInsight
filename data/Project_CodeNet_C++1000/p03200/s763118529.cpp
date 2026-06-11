#include <iostream>

#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  string S;
  cin >> S;
  //入力終了

  int N = S.size();

  //白石に関して，左側にある黒石の数だけ移動できることに着目
  
  //i番目の石の左側に黒石が何個あるか(実装上，自分も含む)
  int left_black_num[N];
  rep(i, N)
    left_black_num[i] = 0;

  //初期値
  if(S[0] == 'B')
    left_black_num[0]++;

  rep(i, N-1){
    int tmp = 0;
    //次が黒石ならカウントの準備
    if(S[i+1] == 'B')
      tmp = 1;
    //「左黒石数」の更新
    left_black_num[i+1] = left_black_num[i]+tmp;
  }

  long long ans = 0;
  //白石に関して，左側にある黒石の数を足していく
  rep(i, N)
    if(S[i] == 'W')
      ans += left_black_num[i];

  //解答
  cout << ans << endl;
  
  return 0;
}
