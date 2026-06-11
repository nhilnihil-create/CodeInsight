#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,num;
  cin >> N;
  num=0;
  // ここにプログラムを追記
  for(int i=0; i<N; i++){
      string S;
      cin >> S;
      if(S=="Y"){
          cout << "Four" << endl;
          num++;
          break;
      }
  }
  if(num==0){
      cout << "Three" << endl;
  }
}
