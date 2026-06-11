#include <bits/stdc++.h>
using namespace std;

 int DigitsSum_A (int A) {
   int sum = 0;
   while (A > 0){
     sum += A % 10;
     A /= 10;
   }
   return sum;
 }

 int DigitsSum_B (int B) {
   int sum = 0;
   while (B > 0){
     sum += B % 10;
     B /= 10;
   }
   return sum;
 }

int main() {
  int N, B, a, b;
  cin >> N;
  
  int min = 1000000;
  
  for (int A = 1; A < N ; A++) {
    B = N - A;
    a = DigitsSum_A(A);
    b = DigitsSum_B(B);
     if (a + b < min)
       min = a + b;
  }
  cout << min << endl;
}