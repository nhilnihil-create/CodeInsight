#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  string S;
  int check = 0; // ひなあられ 'Y' が見つかったかどうかを判定する変数
  for(int i = 0; i < N ; i++){
     cin >> S;
     if(S == "Y"){
     	check = 1;
        break;
     }
  }
  if(check == 0){
  	cout << "Three" << endl;
  }else{
  	cout << "Four" << endl;
  }
}
