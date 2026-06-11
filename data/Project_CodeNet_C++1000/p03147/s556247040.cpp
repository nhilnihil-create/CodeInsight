#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N,h,c = 0,ans = 0;
  cin >> N;
  while(cin >> h) {
    if (h > c) ans += h - c;
    c = h;
  }
  cout << ans << endl;
}
