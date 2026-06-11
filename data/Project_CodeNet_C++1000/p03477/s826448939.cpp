#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, D, X, Y;
  cin >> A >> B >> C >> D;
  X = A + B;
  Y = C + D;
  
  if (X > Y) {
    cout << "Left" << endl;
  }
  
  if (X == Y) {
    cout << "Balanced" << endl;
  }
  
  if (X < Y) {
    cout << "Right" << endl;
  }
}