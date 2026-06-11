#include <iostream>
using namespace std;

int main() {
  long long A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  
  if (A + B >= 2 * C){
    if (X >= Y) cout << min(2 * Y * C + A * (X - Y), 2 * X * C) << endl;
    else cout << min(2 * X * C + B * (Y - X), 2 * Y * C) << endl;
  }
  else {
    cout << A * X + B * Y << endl;
  }
}