#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int a, b, c, d=0, ans=0;
  cin >> a >> b >> c;
  d = max({a, b, c}) * 3 - a - b - c;
  if (d%2==0) {
    ans = d/2;
  } else {
    ans = (d+3)/2;
  }
  cout << ans << endl;
}
