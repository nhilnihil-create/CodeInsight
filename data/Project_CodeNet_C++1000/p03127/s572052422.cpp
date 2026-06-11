#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  int x;
  cin >> x;
  for (int i = 1; i < n; ++i) {
    int y;
    cin >> y;
    x = __gcd(x, y);
  }
  cout << x << endl;
}
