#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A, B, x, y;
  cin >> A >> B;
  
  x = (A + B) % 2;
  if(x == 1) {
    y = (A + B) / 2 + 1; 
  }
  else {
    y = (A + B) / 2;
  }
  cout << y << endl;
}