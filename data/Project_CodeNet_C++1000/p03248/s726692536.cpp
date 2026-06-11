#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <set>
#include <map>
#include <complex>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 1000000007;
long long INF = 1000000000000000; //10^15
typedef long long ll;
typedef unsigned long long ull;

int main(void) {

  int n;
  string s;
  cin >> s;
  n = s.size();

  if (s[n - 1] == '1' || s[0] == '0') {
    cout << -1 << endl;
    return 0;
  }

  for (int i = 0; i < n - 1; i++) {
    if (s[n - 2 - i] != s[i]) {
      cout << -1 << endl;
      return 0;
    }
  }

  int c[100100];
  int m = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '1') {
      c[m++] = i + 1;
    }
  }

  int d[100100];
  d[0] = 0;
  for (int i = 1; i < m; i++) {
    d[i] = c[i] - (c[i - 1] + 1);
  }

  for (int i = 1; i < m + 1; i++) {
    cout << i << " " << i + 1 << endl;
  }

  int j = m + 2;
  for (int i = 2; i <= m; i++) {
    for (int k = 0; k < d[i - 1]; k++) {
      cout << i << " " << j++ << endl;
    }
  }

  return 0;
  
}
