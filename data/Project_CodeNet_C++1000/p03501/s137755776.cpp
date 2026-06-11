#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A, B, P1, P2;
  cin >> N >> A >> B;
  
  P1 = A * N;
  P2 = B;
  
  if (P1 < P2) {
    cout << P1 << endl;
  }
  else{
    cout << P2 << endl;
  }
}