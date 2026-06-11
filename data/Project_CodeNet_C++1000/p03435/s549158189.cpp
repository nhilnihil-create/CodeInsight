#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  vector<vector<int> > c(3, vector<int>(3));
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> c[i][j];
    }
  }
  vector<int> a(3), b(3);
  a[0] = 0;
  b[0] = c[0][0], b[1] = c[0][1], b[2] = c[0][2];
  a[1] = c[1][0] - b[0], a[2] = c[2][0] - b[0];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (a[i] + b[j] != c[i][j]) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}