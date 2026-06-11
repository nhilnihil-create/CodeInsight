#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  // a1の操作可能数を調べる
  int a1;
  cin >> a1;
  
  int a1_divcounter = 0;	//a1が割れる回数
  int a1_dividing = 1;		//a1を割れる数
  
  int divided = a1;	//割られる数(計算用)
  while(1){
    if(divided % 2 == 0){
      a1_divcounter++;
      a1_dividing*=2;
      divided/=2;
    }
    else{
      break;
    }
  }
  
  //a2以降を調べて割れる数の最小値を更新
  int divcounter = a1_divcounter;
  int dividing = a1_dividing;
  for (int i = 0; i < n-1; i++) {
    cin >> divided;
    while(1){
      if (divided % dividing == 0) break;
      else {
        dividing /= 2;
        divcounter--;
      }
    }
    if (divcounter == 0) break;
  }
  
  cout << divcounter << endl;
}
