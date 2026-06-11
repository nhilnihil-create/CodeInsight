#include "bits/stdc++.h"
using namespace std;

int main(){
  int N;
  cin >> N;
  /*
  if(N % 10 == 0){
    cout << "10" << endl;
    return 0;
  }
  */

  int min = 100000;
  for(int i = 1; i < N; i++){
    int num1 = i;
    int num2 = N - i;
    int sum = 0;
    while(num1 != 0 | num2 != 0 ){
      sum += (num1 % 10 + num2 % 10);
      num1 /= 10;
      num2 /= 10;
    }
    if(min > sum){
      min = sum;
    }
  }
  cout << min << endl;
}