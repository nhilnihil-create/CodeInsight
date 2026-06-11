#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B;
  cin >> A >> B;
  
  int C = A+B;
  int D = A-B;
  int E = A*B;
 
  cout << max(C,max(D,E)) << endl;
}

