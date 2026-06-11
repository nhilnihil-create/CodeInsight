#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int a, b, c;
  cin >> a >> b >> c;
  
  int d = max({a, b, c});
  int ans = a + b + c + 9 *d;
  
  cout << ans << endl;

}