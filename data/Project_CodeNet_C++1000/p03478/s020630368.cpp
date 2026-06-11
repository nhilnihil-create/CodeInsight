#include<iostream>
using namespace std;
int sumOfEachDigit(int n){
  int sum_1 = 0;
  while (n > 0){
    sum_1 += n % 10;
    n /= 10;
  }
  return sum_1;
}

int main(){
  int N, A, B, sum_2 = 0;
  cin >> N >> A >> B;
  for(int i = 1; i <= N; i++){
    if(sumOfEachDigit(i) >= A && sumOfEachDigit(i) <= B) sum_2 += i;
  }
  cout << sum_2 << endl;
}