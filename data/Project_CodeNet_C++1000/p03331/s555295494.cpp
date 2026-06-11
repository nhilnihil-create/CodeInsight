#include <iostream>
using namespace std;

int SumOfDigits(int n){
  int sum = 0;
  while(n>0){
    sum += n%10;
    n /= 10;
  }
  return sum;
}

int main(){
  int N;
  cin >> N;
  int min = 100000;
  for(int A=1; A<N; A++){
    int a = SumOfDigits(A);
    int b = SumOfDigits(N-A);
    if(min>a+b){
      min = a+b;
    }
  }
  cout << min;
  return 0;
}