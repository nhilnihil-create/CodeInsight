#include <iostream>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(void){
  string S;
  cin >> S;
  //入力終了

  int N = S.size();

  //文字列の長さが1なら操作はしなくてOK
  if(N == 1){
    cout << 0 << endl;
    return 0;
  }
  
  int ans = 0;
  rep(i, N){
    //次が同じ色なら変換する
    if(S[i] == S[i+1]){
      S[i+1] = (char)('1'-S[i+1] + '0');
      ans++;
    }
  }

  //解答
  cout << ans << endl;
  
  return 0;
}
