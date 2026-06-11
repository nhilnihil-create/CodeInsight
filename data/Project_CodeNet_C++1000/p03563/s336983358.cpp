#include <bits/stdc++.h>
using namespace std;

int main() {
  double b;
  int R, G;
  cin >> R;
  cin >> G;
  /*G = (R + b) / 2;
    G = (R / 2) + (b / 2);
    (b / 2) = G - (R / 2); */
  b = (G * 2) - R;
  cout << b << endl;
}
