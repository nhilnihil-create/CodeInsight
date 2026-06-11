#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef int64_t  ll;

int main () {
  int d, n;
  cin >> d >> n;
  if (d == 0)  {
    if (n == 100) {
      cout << 101 << endl;
    }
    else cout <<  n;
  }  
  else if (d == 1)  {
    if (n == 100) {
      cout << 100 * (n + 1);
    }
    else cout << 100 * n;
  }
  else if (d == 2){
    if (n == 100) {
      cout << 10000 * (n + 1);
    }
    else cout << 10000 * n;
  }
  cout << endl;  
  return 0;
}

//なんでこれでだめかわからん
//nが100だったら101らしい？？？
//d=1 n=100 のときをかんがえる
//100でわりきれる100番目に小さい数。
//nが100だったら10000でこれだと100で2回われる。
//だから100のときは n 101 にして 100番目を担保する
//d=0のときわすれてた てへ///

//全探査