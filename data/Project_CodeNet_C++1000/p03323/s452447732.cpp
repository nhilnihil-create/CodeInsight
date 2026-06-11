#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

const ld pi = 3.141592653589793;

#ifdef EBUG
#define debug(x) cout << "\033[31m" << #x << ": " << x << "\033[0m\n";
#else
#define debug(x)
#endif

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll a, b;
int main() {
  cin >> a >> b;
  if (a > 8 || b > 8) {
    cout << ":(" << endl;
    return 0;
  }
  cout << "Yay!" << endl;
}