#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A;
  int M = 90;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A;
    int j = 0;
    
    while (true) {
      if (A % 2 == 1) {
        break;
      }
      else {
        A /= 2;
        j++;
      }      
    }
    
    if (M > j) {
      M -= (M - j);
    }
    
  }
  cout << M << endl;
  
}