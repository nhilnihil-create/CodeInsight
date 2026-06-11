#include <bits/stdc++.h>
using namespace std;

 int DigitsSum (int n) {
   int sum = 0;
   while (n > 0){
     sum += n % 10;
     n /= 10;
   }
   return sum;
 }

int main() {
  int N, B, a, b;
  cin >> N;
  
  int min = 1000000;
  
  for (int A = 1; A < N ; A++) {
    B = N - A;
    a = DigitsSum(A);
    b = DigitsSum(B);
     if (a + b < min)
       min = a + b;
  }
  cout << min << endl;
}