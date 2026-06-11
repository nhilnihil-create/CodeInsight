#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

int main() {
  int a, b, c;

  #ifdef DEBUG
  freopen("5-08-a.txt", "r", stdin);
  #endif

  while (cin >> a >> b) {
    c = a * b;
    cout << (c % 2 == 0 ? "Even" : "Odd") << endl;
  }

  return 0;
}
