#include <bits/stdc++.h>
using namespace std;

int CalcSumOfDigit(int n){
  int sum = 0;
  while(n > 0){
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main() {
  int N;
  cin >> N;
  
  int sum_sum = 0;
  int sum_min = 100000;
  for(int i=1;i<N;i++){
    sum_sum = CalcSumOfDigit(i) + CalcSumOfDigit(N-i);
    if(sum_sum < sum_min ){
      sum_min = sum_sum;
    }
  }
  cout << sum_min << endl;
}