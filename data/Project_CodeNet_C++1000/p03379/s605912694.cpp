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
  vector<int> x(n);
  vector<int> y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    y[i] = x[i];
  }
  sort(y.begin(), y.end());

  for (int i = 0; i < n; i++) {
    if (x[i] < y[n/2]) {
      cout << y[n/2] << endl;
    } else {
      cout << y[n/2-1] << endl;
    }
  }

  return 0;
}