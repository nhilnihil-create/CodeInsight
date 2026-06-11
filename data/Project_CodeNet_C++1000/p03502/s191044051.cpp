#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N;
  cin >> N;
  int original = N;

  // 桁数を計算する
  int ten = 10;
  int digit = 1;
  while(N / ten >= 1){
    ten *= 10;
    digit++;
  }

  int divide = 1;
  for(int i = 1; i < digit; i++){
    divide *= 10;
  }

  int sum = 0;
  for(int i = digit; i >= 1; i--){
     sum += N / divide;
     N %= divide;
     divide /= 10;
  }

  if(original % sum == 0){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}