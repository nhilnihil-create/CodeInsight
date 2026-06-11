#include <bits/stdc++.h>
using namespace std;

int main(){
  int A, B;
  cin >> A >> B;

  int count = 0;

  for(int i = A; i < B + 1; i++){

    int copy = i;
    int original = i;

    // iの桁数を計算する
    int ten = 10;
    int digit = 1;
    while(copy / ten >= 1){
      ten *= 10;
      digit++;
    }
    
    // iを反転した値を計算する
    int divide = 1;
    for(int j = 1; j < digit; j++){
      divide *= 10;
    }
    
    int sum = 0;
    int multiply = 1;
    for(int j = digit; j >= 1; j--){
      int palindromic = copy / divide;
      sum += palindromic * multiply;
      
      multiply *= 10;
      
      copy %= divide;
      
      divide /= 10;
    }

    if(original == sum){
      count++;
    }
  }
  cout << count << endl;
}
