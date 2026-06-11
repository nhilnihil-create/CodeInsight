#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  cout << min(a, b) << ' ';
  cout << max(0, a + b - n) << '\n';
  return 0;
}
