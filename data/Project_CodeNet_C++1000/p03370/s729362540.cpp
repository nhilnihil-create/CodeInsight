#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using ll = long long;

int main()
{
  int a,b,c=0,d,e,f=1001;
  cin >> a >> b;
  e = a;
  while (a--) {
    cin >> d;
      c+= d;
      if (d < f) {
        f = d;
      }
  }
  cout << ((b-c)/f) + e << endl;
  return 0;
}
