#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  
  int cost1 = A * X + B * Y;
  int cost2 = 2 * C * max(X, Y);
  int cost3;
  if (X > Y) {
    cost3 = 2 * C * Y + A * (X - Y);
  } else {
    cost3 = 2 * C * X + B * (Y - X);
  }
  if (cost1 >= cost2) {
    if (cost2 >= cost3) {
      cout << cost3 << endl;
    } else {
      cout << cost2 << endl;
    }
  } else {
    if (cost1 >= cost3) {
      cout << cost3 << endl;
    } else {
      cout << cost1 << endl;
    }
  } 
}
