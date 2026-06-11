#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;

  int min_price;

  for (int i = 0; i <= X + Y; i++) {
    int price = 2 * C * i + A * max(0, X - i) + B * max(0, Y - i);
    min_price = (i == 0) ? price : min(min_price, price);
  }

  cout << min_price << endl;
}