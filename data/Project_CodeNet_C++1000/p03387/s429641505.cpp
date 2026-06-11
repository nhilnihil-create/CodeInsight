#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C;
  cin >> A >> B >> C;
  
  int M = max(max(A, B),C);
  int D = 3*M - (A+B+C);
  
  if (D%2 == 0){
    cout << D/2 << endl;
  }
  else {
    cout << (D+3)/2 << endl;
  }
}