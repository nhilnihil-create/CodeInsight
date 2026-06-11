#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int S, a, b, c, d;
  cin >> S;
  
  a = S % 10;
  b = (S - a) /10 % 10;
  c = (S - a - b * 10) / 100;
  d = a + b + c;
  
  cout << d << endl;
}
