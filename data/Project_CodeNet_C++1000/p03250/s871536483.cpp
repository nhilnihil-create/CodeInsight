#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int d1 = a * 10 + b + c;
  int d2 = a + b * 10 + c;
  int d3 = a + b + c * 10;
  cout << max({d1, d2, d3}) << endl;
}
