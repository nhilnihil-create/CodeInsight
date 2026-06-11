#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, K; 
  cin >> N >> K;
  int f = 1;
  //2,4,8,16,32,
  //二倍したときとKを足したときにどちらが小さいか比べる
  
  for (int i = 0; i < N; i++){
    
    if (f * 2 <= f + K){
      f = f * 2;
    }
    else if (f * 2 > f + K){
      f = f + K;
    }
    
  }
  
  cout << f << endl;
  

 }