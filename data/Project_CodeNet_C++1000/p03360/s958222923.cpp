#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int main(void) {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  cout << a + b + c - max(a, max(b, c)) + max(a, max(b, c)) * pow(2, k) << endl;

  return 0;
}
