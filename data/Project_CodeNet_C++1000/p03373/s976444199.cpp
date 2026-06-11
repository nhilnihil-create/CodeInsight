#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  int lowerC_AB;
  lowerC_AB = 2 * c < (a + b) ? 2 * c : a + b;
  int smaller;
  smaller = x < y ? x : y;
  int total = 0;
  total += smaller * lowerC_AB;
  if (x < y) {
    int lowerB_C = b < c * 2 ? b : c * 2;
    total += (y - x) * lowerB_C;
  } else {
    int lowerA_C = a < c * 2 ? a : c * 2;
    total += (x - y) * lowerA_C;
  }
  cout << total << endl;
  return 0;
}