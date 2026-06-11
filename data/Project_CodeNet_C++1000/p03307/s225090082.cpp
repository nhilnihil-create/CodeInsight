#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans = n * (n%2 + 1);
  cout << ans << "\n";
  return 0;
}