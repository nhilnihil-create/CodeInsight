#include <iostream>
using namespace std;

int FindSomeOfDigits(int n){
  int sum = 0;
  while(n>0){
    sum+=n%10;
    n/=10;
  }
  return sum;
}

int main() {
  int N,A,B;
  std::cin >>N>> A>>B;
  int count=0;
  for (int i = 0; i < N+1; i++) {
    /* code */
    int sum=FindSomeOfDigits(i);
    if(sum>=A && sum<=B){
      count+=i;
    }
  }
  cout << count<<endl;
}
