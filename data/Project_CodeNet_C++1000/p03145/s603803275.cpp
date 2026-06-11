#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C;
  cin >> A >> B >> C;
  
  if (A>B && A>C){
    cout << B*C/2 << endl;
  }
  else if (B>A && B>C){
    cout << A*C/2 << endl;
  }
  else if (C>B && C>A){
    cout << B*A/2 << endl;
  }
}
  