#include <bits/stdc++.h>
using namespace std;
 
int main() {
  double a(0), b(0); 
  cin >> a; 
  cin >> b;
  const double x = (a + b) * 0.5;
  const int xCast = static_cast<int>(x);
  
  if( x == xCast )
  {
      cout << xCast << endl;
  }
  else 
  {
      cout << xCast + 1 << endl;
  }
}