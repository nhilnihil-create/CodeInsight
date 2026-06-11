#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  LL r, D, x; cin >> r >> D >> x;
  for (int i = 1; i <= 10; ++i) {
    x = r * x - D;
    cout << x << endl;
  }
}
