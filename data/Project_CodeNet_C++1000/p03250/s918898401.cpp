#include <bits/stdc++.h>
using namespace std;

int main () {
  int a,b,c;
  cin >> a >> b >> c;

  int xa=max({a,b,c}),xb=min({a,b,c});
  cout << 10*xa+(a+b+c-xa-xb)+xb << endl;
  return 0;
}
