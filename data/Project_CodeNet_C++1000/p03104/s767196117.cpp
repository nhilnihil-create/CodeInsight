#include <iostream>
#include <vector>
using namespace std;

int main() {
  long a, b;
  cin >> a >> b;
  long ans = 0;
  if (a % 2 == 1) {
    ans ^= a;
    a++;
  }
  if (b % 2 == 0) {
    ans ^= b;
    b--;
  }
  if (a < b) {
    ans ^= (b - a + 1) / 2 % 2;
  }
  cout << ans << endl;
  return 0;
}
