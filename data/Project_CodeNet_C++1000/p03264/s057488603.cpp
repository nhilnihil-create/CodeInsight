#include <iostream>
using namespace std;
int main() {
  int k;
  cin >> k;
  int ans = k/2 * (k - k/2);
  cout << ans << endl;
  return 0;
}