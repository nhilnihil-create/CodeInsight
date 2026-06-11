#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, A, x, y;
  y = 0;
  cin >> N;
  
  for (int i = 0; i < 1; i++) {
    cin >> A;
    x = 0;
    for (int j = 0; j < 29; j++) {
      if (A % 2 != 0) break;
      else if (A % 2 == 0) {
      A /= 2;
      x++;
      }
    }
  }
  
  y = x;
  
  for (int i = 0; i < N - 1; i++) {
    cin >> A;
    x = 0;
    
    for (int j = 0; j < 29; j++) {
      if (A % 2 != 0) { 
        if (x <= y) { 
          y = x;
        }
        break;
      }
      
      else if (A % 2 == 0) {
      A /= 2;
      x++;
      }
    }
  }
  cout << y << endl;
}