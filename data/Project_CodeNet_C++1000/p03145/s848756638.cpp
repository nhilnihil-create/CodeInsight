#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int A, B, C, x1, x2, x3;
  cin >> A >> B >> C;
  
  x1 = max(A,max(B,C));
  x3 = min(A,min(B,C));
  x2 = A+B+C-(x1+x3);

  cout << x2*x3/2 << endl;
  
}