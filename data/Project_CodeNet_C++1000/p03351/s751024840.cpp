#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (std::abs(a-c) <= d) {
    cout << "Yes" << endl;
  } else if (std::abs(a-b) <= d && std::abs(b-c) <= d) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
