#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(void){
  int N, D, X;
  cin >> N >> D >> X;
  int A[N];
  rep(i, N)
    cin >> A[i];
  //入力終了

  //1日目に食べる分を0日目にずらす
  D--;
  
  int ans = 0;
  rep(i, N){
    //1日目に食べるため1で初期化
    int tmp = 1;
    //0日目から何回食べられるか
    tmp += D/A[i];
    ans += tmp;
  }

  //解答
  //残っていたチョコを足す
  cout << ans + X << endl;
  
  return 0;
}
