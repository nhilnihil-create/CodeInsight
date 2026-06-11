#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  
  int A = 1;
  int B1, B2;
  
  for (int i = 0; i < N; i++) {
    
    B1 = A * 2;
    B2 = A + K;
    
    if (B1 > B2) {
      A = B2;
    } else {
      A = B1;
    }
  }
  
  cout << A << endl;
}