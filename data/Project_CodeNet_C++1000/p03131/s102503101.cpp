#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int main(){
  long long K, A, B;
  cin >> K >> A >> B;
  //入力終了

  //操作回数の上限より，円経由交換による操作の方が多い
  if(K < A+1){
    cout << K+1 << endl;
    return 0;
  }
  //円を経由するよりも直接ビスにした方が効率が良い
  if(A+2 >= B){
    cout << K+1 << endl;
    return 0;
  }

  long long ans = 0;
  
  //1回目の操作
  K = K-(A-1);   //初めに1個持っている
  K--;           //Aビスを1円に
  ans += B; K--; //1円をBビスに

  //AビスがBビスに変わるが，A<BよりBビスの一部を使って操作を繰り返せる．
  //よって，操作を繰り返せる回数は，Aビス->1円，1円->Bビスの2回の操作を
  //何回繰り返せるかによる
  long long change_count = K/2;
  
  //AビスをBビスにchange_count回変換できる
  ans = ans+( (B-A)*change_count);    
  
  //残った操作回数はビスを増やす
  ans += K%2;
  
  //解答
  cout << ans << endl;
  
  return 0;
}
