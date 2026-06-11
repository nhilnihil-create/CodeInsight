#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  int D = A + B;
  
  if(C <= D) cout << C + B << endl;
  if(C > D) cout << B + D + 1 << endl;
}