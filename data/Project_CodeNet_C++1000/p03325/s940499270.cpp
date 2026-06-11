#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

const ld pi = 3.141592653589793;

ll n, a, c;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    while (a % 2 == 0) {
      c++;
      a /= 2;
    }
  }

  cout << c << endl;
}