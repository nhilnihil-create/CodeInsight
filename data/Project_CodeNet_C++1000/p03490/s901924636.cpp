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

vector<vector<bool>> dpx, dpy;

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
  int l = (int)s.length();
  vector<int> mx, my;
  for (int i = 0; i < m.size(); i++) {
    if (i % 2) my.push_back(m[i]);
    else mx.push_back(m[i]);
  }
  
  dpy = vector<vector<bool>>(my.size() + 1, vector<bool>(l * 2 + 1, false));
  dpy[0][l] = true;
  for (int i = 0; i < my.size(); i++) {
    for (int j = 0; j <= 2 * l; j++) {
      if (dpy[i][j]) {
        dpy[i + 1][j + my[i]] = true;
        dpy[i + 1][j - my[i]] = true;
      }
    }
  }
  dpx = vector<vector<bool> >(mx.size() + 1, vector<bool> (2 * l + 1, false));
  dpx[1][l + mx[0]] = true;
  for (int i = 1; i < mx.size(); i++) {
    for (int p = 0; p <= 2 * l; p++) {
      if (dpx[i][p]) {
        dpx[i + 1][p + mx[i]] = true;
        dpx[i + 1][p - mx[i]] = true;
      }
    }
  }
  
  if (dpx[mx.size()][x + l] && dpy[my.size()][y + l]) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  
  return 0;
}
