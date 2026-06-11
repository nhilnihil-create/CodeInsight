#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A,B,C;
  cin >> N;
  A = 0;
  C = N;
  
  for (int i = 0; i < 9; i++) {
    B = 1;
      for (int j = 8 - i; j > 0; j--) {
        B *= 10;   
      }
    
    A += C / B;
    C %= B;
  }
  
  if (N % A == 0) {
    cout << "Yes" << endl;
  }  
  
  else { cout << "No" << endl; }
  
}