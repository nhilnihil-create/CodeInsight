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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int g = 1; g <= n; g++) {
    if (n <= k + (k-1) * (g-1)) {
      cout << g << endl;
      return 0;
    }
  }
  return 0;
}