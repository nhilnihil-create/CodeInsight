#include <iostream>
using namespace std;

int digits_sum(int x){
  int sum = 0;
  while(x > 10){
     sum += x % 10;
     x /= 10;
  }
  return sum += x;
}

int main(void){
  int N;
  cin >> N;
 
  if(N % 10 == 0) cout << "10" << "\n";
  else cout << digits_sum(N) << "\n";
}
