#include <bits/stdc++.h>
using namespace std;

int main() {
  int R, L, A, B, C, D;
  cin >> A >> B >> C >> D;
  L = A + B;
  R = C + D;
  
  if (L > R) {
    cout << "Left" << endl;
  }
  
  if (L == R) {
    cout << "Balanced" << endl;
  }
  
  if (L < R) {
    cout << "Right" << endl;
  }
}