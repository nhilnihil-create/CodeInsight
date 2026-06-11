#include <iostream>
#include <algorithm>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main(){
  int N, H;
  cin >> N >> H;
  int a[N], b[N];
  rep(i, N)
    cin >> a[i] >> b[i];
  //入力終わり

  //ソートしても一般性を失わない
  sort(b, b+N, greater<>() );
  
  //a[ ]の最大を求める
  int a_max = 0;
  rep(i, N)
    if(a_max < a[i])
      a_max = a[i];

  int count = 0;

  //相手の体力が残っている間
  //ATKの大きい剣から投げていく
  while(count<N && H>0){
    //投げるより振った方がいいならwhile抜ける
    if(b[count] < a_max)
      break;
    H -= b[count++];
  }

  int tmp = 0;
  //投げるだけで倒せないとき
  if(H>0){
    //残り体力がa_maxで割り切れれば，普通に割ればよい
    if(H%a_max == 0)
      tmp = H/a_max;
    //割り切れなければ，商の切り上げ
    else
      tmp = (H+a_max)/a_max;
  }
  count += tmp;
  
  //解答
  cout << count << endl;
  
  return 0;
}
