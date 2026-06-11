#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, sum, x;
  cin >> A >> B;
  sum = 0;
  x = A;
  
  for(int i = 0; i <= B - A; i++ ){
    int a, b, c, d;  
    a = x / 10000;
    b = (x % 10000) / 1000; 
    c = (x % 100) / 10;
    d = x % 10;
    if(a == d && b == c  ){
      sum = sum + 1; 
    }
    x = x + 1;
  }
  cout << sum << endl;
  
}