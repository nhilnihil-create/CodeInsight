#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  // ここにプログラムを追記
  int Num = 1;
  for(int i=0; i<N; i++) {
  	if(Num*2 > Num+K) {
      Num += K;
    }
    else {
      Num *= 2;
    }
  }
  cout << Num << endl;
}