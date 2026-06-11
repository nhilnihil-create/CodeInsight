#include<bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
  C *= 2;
  int XY;
  if(X > Y) {
    cout << min(C * X, min(C * Y + A * (X - Y), A * X + B * Y)) << endl;
  }  else {
    cout << min(C * Y, min(C * X + B * (Y - X), A * X + B * Y)) << endl;
  }
}
