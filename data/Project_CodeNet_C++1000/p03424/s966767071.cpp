#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  int P = 0;
  int W = 0;
  int G = 0;
  int Y = 0;
  
  cin >> N;

  // ここにプログラムを追記
  for(int i = 0; i < N; i++){
	cin >> S;
    
 	//debug
    //cout << i << endl;
    //cout << S << endl;
    
    if (S == "P"){
      P = 1;
    }
    else if (S == "W"){
      W = 1;
    }
    else if (S == "G"){
      G = 1;
    }
    else if (S == "Y"){
      Y = 1;
    }

	//debug
    //cout << P << W << G << Y << endl;
    
    //4種類が入っている事が確定したらここで終了
    if ((P + W + G + Y) == 4){
      cout << "Four" << endl;
      break;
    }

    //最後まで取り出しても4種類無い場合
    if (i == N -1){
    	cout << "Three" << endl;
    }
    
  }
  
}
