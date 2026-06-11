#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d, e, f, g, h, i;
  cin >> a >> b >> c;
  
  d = abs(a-b) + abs(c-b);
  e = abs(a-c) + abs(c-b);
  f = abs(b-a) + abs(a-c);
  g = abs(b-c) + abs(c-a);
  h = abs(c-a) + abs(a-b);
  i = abs(c-b) + abs(b-a);
   
  cout << min(min(min(min(min(d,e),f),g),h),i) << endl;
  
}
