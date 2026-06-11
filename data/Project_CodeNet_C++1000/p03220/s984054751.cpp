#include <iostream>
using namespace std;
int main() {
  int n,t,a;
  cin >> n >> t >> a;
  t *= 1000;
  a *= 1000;
  int m = 1000000000;
  int ans = 0;
  for(int i = 1; i <= n; i++) {
    int h;
    cin >> h;
    if (m > abs(t - h*6 - a)) {
      m = abs(t - h*6 - a);
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}