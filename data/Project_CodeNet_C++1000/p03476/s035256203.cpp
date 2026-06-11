#include <iostream>
#include <list>
#include <map>

#define rep(i, n) for(int i=0; i<n; i++)

using namespace std;

int MAX = 100000;

int main(void){

  //iが素数かどうか
  bool flag[MAX+1];
  rep(i, MAX+1)
    flag[i] = true;

  //素数でない数のフラグを下ろす
  for(int n=2; n<=MAX; n++)
    if(flag[n] )
      for(int m=n+n; m<=MAX; m+=n)
	flag[m] = false;

  //n以下の数字の中に「2017に似た数」がいくつあるか
  int count[MAX+1];
  rep(i, MAX+1)
    count[i] = 0;

  for(int n=3; n<=MAX; n+=2)
    //「2017に似た数」判定
    if(flag[n] && flag[(n+1)/2])
      count[n]++;

  //累積和
  for(int i=3; i<=MAX; i++)
    count[i] = count[i]+count[i-1];

  //入力
  int Q;
  cin >> Q;

  int l, r;
  rep(i, Q){
    cin >> l >> r;
    //累積和を利用したカウント
    cout << count[r] - count[l-1] << endl;
  }
  
  return 0;
}
