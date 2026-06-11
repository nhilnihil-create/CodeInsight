#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(void){
  int N;
  cin >> N;
  int A[N];
  bool flag = true;
  rep(i, N){
    cin >> A[i];
    if((A[i]&1) == 1)
      flag = 0;
  }
  //入力終了

  int ans = 0;
  while(flag){
    rep(i, N){
      A[i] = A[i]/2;
      //奇数になったらフラグをfalseにして終了
      if((A[i]&1) == 1)
	flag = false;
    }
    ans++;
  }

  //解答
  cout << ans << endl;
  
  return 0;
}
