#include <iostream>

using namespace std;

int gcd(int x, int y) {
  if (x < y) swap(x, y);
  while (y > 0) {
    auto r = x % y;
    x = y;
    y = r;
  }
  return x;
}

int main() {
  int N,X,ans,x;
  cin >> N >> X >> x;
  ans = abs(x-X);
  while(cin >> x) ans = gcd(ans,abs(x-X));
  cout << ans << endl;
}
