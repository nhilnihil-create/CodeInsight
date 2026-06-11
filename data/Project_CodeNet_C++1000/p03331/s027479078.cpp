#include <bits/stdc++.h>

using namespace std;

int findSumOfDigits(int n) {
  int sum = 0;
  while(n > 0) {
    sum += n % 10;
      n /= 10;
  }
  return sum;
}


int main()
{
  int N;
  cin >> N;
  
  int sum_digit;
  int min = 1000000;
  
  
  for (int i = 1; i < N; i++) {
      sum_digit = findSumOfDigits(i) + findSumOfDigits(N-i);
      if(sum_digit < min) {
        min = sum_digit;
    }
  }
  cout << min << endl;
}