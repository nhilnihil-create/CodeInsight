#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  // ここにプログラムを追記
  string S = "", Num;
  for(int i = 0; i < N; i++) {
  	cin >> S;
    
    if(S == "Y") {
      Num = "Four";
      break;
    }
    else if( Num != "Four") {
      Num = "Three";
    }
  }
  cout << Num << endl;
}