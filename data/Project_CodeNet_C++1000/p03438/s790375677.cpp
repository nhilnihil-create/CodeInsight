#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <memory>
#include <deque>
#include <set>
#include <unordered_set>
#include <cmath>
#include <list>
#include <cassert>
#include <cstring>

using namespace std;

using big = long long;

const int N = 20000;

big a[N];


int main() {
	std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a[i] += x;
  }
  for (int i = 0; i < n; ++i) {
    int x;
    
    cin >> x;
    a[i] -= x;
  }
  big s = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) {
      s += a[i];
      a[i] = 0;
    }
  }
  s *= 2;
  for (int i = 0; i < n; ++i) {
    if (a[i] < 0) {
      big v = min(-a[i] / 2 * 2, s);
      a[i] += v;
      s -= v;
    }
  }
  if (s <= 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
