#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B;
  cin >> A >> B; 
  int S = 0;
  for (int i = 0; i < B - A + 1; i++) {
    int a, b, c, d;
    a = ( A + i ) / 10000;
    b = ( A + i ) / 1000 % 10;
    c = ( A + i ) / 10 % 10;
    d = ( A + i ) % 10;
    if ( a == d && b == c) {S++;}
  }
  cout << S << endl;
}