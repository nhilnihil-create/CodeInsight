#include <bits/stdc++.h>
using namespace std;

int main() {
  string c, ans;
  
  cin >> c;
  
  if ((c[0]==c[1] && c[0]==c[2]) || (c[3]==c[2] && c[3]==c[1])) ans = "Yes";
  else ans = "No";
  
  cout << ans << endl;
}
