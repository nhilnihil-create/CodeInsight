#include<bits/stdc++.h>
using namespace std;

int main(void){
  int n, a = 0;		//n:正の整数の個数	a:宣言した整数が同時に2で割れる数
  cin >> n;
  
  for( int i = 0 ; i < n ; i++ ){
    int k, w = 0;		//k:宣言する整数 w:i番まで宣言した整数が同時に2で割れる数
    cin >> k;
    while(true){
      if( k % 2 == 1)  break;
      k /= 2;
      w++;
    }
    if( i == 0 || a > w )  a = w;
  }
  cout << a << endl;
}
    