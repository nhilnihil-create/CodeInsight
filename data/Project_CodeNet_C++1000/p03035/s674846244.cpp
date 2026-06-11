#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,r;
  cin >> a >> b;

  if(a <= 5)
  {
    r = 0;
  }
    if(a <= 12 && a>=6)
  {
    r = b/2;
  }
      if(a > 12)
  {
    r = b;
  }
  
  cout << r;
}