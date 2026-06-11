#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b;
  cin >> a >> b;
  int ans;
  if ( (a+b)%2 == 0 ) ans = (a+b)/2;
  else ans = (a+b)/2 +1;
  cout << ans << endl;
  
  return 0;
}
