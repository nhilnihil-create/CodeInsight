#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c, d, l, r;
  string ans;
  
  cin >> a >> b >> c >> d;
  
  l = a + b;
  r = c + d;
  if (l == r) ans = "Balanced";
  else if (l>r) ans = "Left";
  else ans = "Right";
  
  cout << ans << endl;  
}