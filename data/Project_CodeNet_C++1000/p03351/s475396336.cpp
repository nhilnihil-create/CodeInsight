#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
using namespace std;

void solve(){
  int a, b, c, d; cin >> a >> b >> c >> d;
  string ans;
  if(abs(a - c) <= d) ans = "Yes";
  else if(abs(a - b) <= d && abs(b - c) <= d) ans = "Yes";
  else ans = "No";
  cout << ans << endl;
  return;
}
int main(){
  solve();
  return 0;
}
