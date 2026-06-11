#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int Sumofdigits(int n){
  int sum=0;
  while (n>0){
    sum += n%10;
    n /=10;
  }
  return sum;
}
  
int main() {
  int N, min;
  cin >> N;
  min = 100000;
  
  for (int i=1; i<N; i++){
    int sum1 = Sumofdigits(i);
    int sum2 = Sumofdigits(N-i);
    int sum = sum1 + sum2;
    if (min > sum){
      min = sum;
    }
  }
   cout << min << endl;
    
    
}