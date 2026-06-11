#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <map>
#include <set>
using namespace std;

void solve(){
  int a, b, c, d; cin >> a >> b >> c >> d;
  string ans;
  if(a + b > c + d) ans = "Left";
  else if(a + b < c + d) ans = "Right";
  else ans = "Balanced";
  cout << ans << endl;
  return;
}

int main(){
  solve();
  return 0;
}
