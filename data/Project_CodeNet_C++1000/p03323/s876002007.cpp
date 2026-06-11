#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b; cin>>a>>b;
  string ans = "Yay!";
  if (a > 8 || b > 8) ans = ":(";
  cout << ans << endl;
}