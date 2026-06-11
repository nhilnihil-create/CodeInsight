#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <numeric>
#include <cmath>
#include <queue>
#include <sstream>
#include <string.h>
#include <bitset>
#include <stack>

using namespace std;
typedef long long ll;

int main() {
  string s;
  int x, y;
  cin >> s >> x >> y;
  vector<int> m;
  int n = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'T') {
      m.push_back(n);
      n = 0;
    } else {
      n++;
    }
  }
  if (n > 0) {
    m.push_back(n);
  }
  
  vector<int> mx, my;
  int f = m[0];
  for (int i = 1; i < m.size(); i++) {
    if (i % 2) my.push_back(m[i]);
    else mx.push_back(m[i]);
  }
  
  sort(mx.rbegin(), mx.rend());
  sort(my.rbegin(), my.rend());

  x -= f;
  
  for (auto it : mx) {
    x = abs(abs(x) - it);
  }
  for (auto it : my) {
    y = abs(abs(y) - it);
  }
  
  if (x != 0 || y != 0) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}
