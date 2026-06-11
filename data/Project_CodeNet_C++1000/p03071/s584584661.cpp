#include <bits/stdc++.h>
using namespace std;
     
int main() {
  int a, b, s = 0;
  cin >> a >> b;
  
  if (a >= b) {
    s = a;
    a--;
  } else {
    s = b;
    b--;
  }
  
  if (a >= b) s = s + a;
  else s = s + b;

  cout << s << endl;
}