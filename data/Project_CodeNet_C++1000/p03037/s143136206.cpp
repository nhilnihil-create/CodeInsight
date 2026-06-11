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
  int n, m;
  cin >> n >> m;
  vector<int> l(m), r(m);
  for (int i = 0; i < m; ++i) {
    cin >> l[i] >> r[i];
  }
  int ri = r[0], le = l[0];
  for (int i = 1; i < m; ++i) {
    ri = min(ri, r[i]);
    le = max(le, l[i]);
  }
  cout << max(0, ri - le + 1) << endl;
  return 0;
}