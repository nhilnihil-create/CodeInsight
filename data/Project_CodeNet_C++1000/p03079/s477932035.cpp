#include <iostream>
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b, c; cin >> a >> b >> c;
  bool flag = false;
  if(a == b && b == c && c == a) flag = true;
  
  cout << (flag ? "Yes" : "No") << '\n';
  return 0;
}
