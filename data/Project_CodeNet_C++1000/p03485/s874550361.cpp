#include <bits/stdc++.h>

using namespace std;

int main() {

  double a, b;
  double ave;

  cin >> a >> b ;

  ave = (a + b) / 2;
  double v = (ave / 0.1);

  int n = v;
  n = n % 10;

  if (5 <= n && n <= 9) { n = 1; }
  else { n = 0; }

  int c;
  
  if (n == 1) {
    c = ave;
    c += 1;
  } else if (n == 0) {
    c = ave;
  }

  cout << c << endl;  

  return(0);
}