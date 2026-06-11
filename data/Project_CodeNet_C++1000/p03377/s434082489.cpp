#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,x;cin>>a>>b>>x;
  string ans = "NO";
  if (x < a) ans = "NO";
  else if (b >= x - a) ans = "YES";
  cout << ans << endl;
}
