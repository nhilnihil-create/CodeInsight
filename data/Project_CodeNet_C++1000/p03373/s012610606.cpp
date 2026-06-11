#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  
  int AB = A + B;
  int XY = min(X, Y);
  
  X -= XY;
  Y -= XY;
  C *= 2; 
  
  int res = min(AB, C) * XY;
  
  if(X) res += min(A, C) * X;
  if(Y) res += min(B, C) * Y;
 
  cout << res << endl;
  
}