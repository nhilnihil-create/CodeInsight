#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int ans = a;
  if (b < a) {
    ans--;
  }
  cout << ans << endl;
  return 0;
}
