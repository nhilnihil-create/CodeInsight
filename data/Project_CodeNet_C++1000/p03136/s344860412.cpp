#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <sstream>
#include <fstream>
#include <climits>
#include <map>
#include <numeric>
#include <functional>
#include <utility>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main(void) {
  int n;
  cin >> n;
  vector<int> l(n);
  rep(i, n) cin >> l[i];
  sort(l.begin(), l.end(), greater<int>());
  int sum = 0;
  for (int i = 1; i < n; i++) {
    sum += l[i];
  }
  cout << (l[0] < sum ? "Yes" : "No") << endl;
  return 0;
}
