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
#include <numeric>
using namespace std;
typedef long long ll;

int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int r = accumulate(a.begin(), a.end(), 0, [](int m, int n) {
    return gcd(m, n);
  });

  cout << r << endl;

  return 0;
}