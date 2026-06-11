#include<bits/stdc++.h>
using namespace std;
int main() {
  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
  C *= 2;
  int sum = 0;
  if(A + B < C) {
    cout << A * X + B * Y << endl;
  } else if(X >= Y) {
    if(A >= C) {
      cout << C * X << endl;
    } else {
      cout << (X - Y) * A + C * Y << endl;
    }
  } else {
    if(B >= C) {
      cout << Y * C << endl;
    } else {
      cout << X * C + (Y - X) * B << endl;
    }
  }
}
