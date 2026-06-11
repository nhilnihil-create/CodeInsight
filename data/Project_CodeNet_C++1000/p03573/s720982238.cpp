#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int A, B, C;
  cin >> A >> B >> C;
  
  if (A == B) {
    cout << C << endl;
  }
  else if (B == C) {
    cout << A << endl;
  }
  else if (C == A) {
    cout << B << endl;
  }
  
return 0;
}