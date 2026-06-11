#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int A, B, a1, a2, a3, a4, a5;
  int N = 0;
  
  cin >> A >> B;

  for(int i = 0;i < B; i++) {
  
    a1 = A / 10000;
    a2 = (A - a1 * 10000) / 1000;
    a3 = (A - a1 * 10000 - a2 * 1000) / 100;
    a4 = (A - a1 * 10000 - a2 * 1000 - a3 * 100) / 10;
    a5 = A % 10;
  
    if(a1 == a5 && a2 == a4) {
      N += 1;
    }
    
    A += 1;
    if(A > B) {
      break;
    }
    
  }
  
  cout << N << endl;

}