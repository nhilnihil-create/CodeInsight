#include <bits/stdc++.h>
using namespace std;

int main() {
  double a, b, R, G;
  
  cin >> R >> G;
  
  a = R;
//  G == (a + b) / 2;
  b = 2 * G - a;
  
  cout << b << endl;
}