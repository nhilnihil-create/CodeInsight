#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  ll n, m;
  cin >> n >> m;

  if (n >= 2 && m >= 2) {
    cout << (n-2) * (m-2) << endl;
  } else if (n == 1 && m == 1) {
    cout << 1 << endl;
  } else if (n == 1 && m > 1) {
    cout << m - 2 << endl;
  } else if (m == 1 && n > 1) {
    cout << n - 2 << endl;
  }
  return 0;
}