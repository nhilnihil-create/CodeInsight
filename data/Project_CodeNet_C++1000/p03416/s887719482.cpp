#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B, x, sum;
  cin >> A >> B;
  sum = 0;
  x = A; 
  
  for (int i = 0; i <= B - A; i++) {
  int a = x % 10;
  int b = x % 100 / 10;
  int c = x % 10000 / 1000;
  int d = x / 10000;
    
    if (a == d && b == c) sum++;
    if (x == B) break;
   
  x++;
  }
  cout << sum << endl;
}