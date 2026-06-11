#include <iostream>

using namespace std;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  int mx = max(a, max(b, c));
  cout << a + b + c - mx + (mx << k) << endl;
}
