#include <bits/stdc++.h>
#include <cmath>
using namespace std;
 
int main() {
  int a;
  int b;
  cin >> a >> b;
  double r = (a + b) / 2.0;
  double m = r / 2;
  if (m > 0.0) {
    r = ceil(r);
  } 
  cout << (int) r << endl;
}
