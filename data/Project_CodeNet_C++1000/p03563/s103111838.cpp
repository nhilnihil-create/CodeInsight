#include <bits/stdc++.h>

using namespace std;

int main() {
  
  int a, b;

  cin >> a >> b;

  // b = (a + n) / 2
  a += (b - a) * 2 ;
  cout << a << endl;

  return(0);
}