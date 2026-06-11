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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int d = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) {
      d += abs(0-a[i]);
    } else {
      d += abs(a[i-1]-a[i]);
    }
  }
  d += abs(a[n-1]);

  for (int i = 0; i < n; i++) {
    if (i == 0) {
      cout << d - abs(0-a[i]) - abs(a[i]-a[i+1]) + abs(0-a[i+1]) << endl;
    } else {
      cout << d - abs(a[i-1]-a[i]) - abs(a[i]-a[i+1]) + abs(a[i-1]-a[i+1]) << endl;
    }
  }

  return 0;
}
