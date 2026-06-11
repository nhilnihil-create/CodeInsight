#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  string s, t;
  cin >> s;
  int n = s.length();
  vector<int> num;
  for(int i = 0; i < n; i++) {
    if(s[i] != 'x') {
      t += s[i];
      num.push_back(i);
    }
  }
  int m = t.length();
  string rt = t, rs = s;
  reverse(rt.begin(), rt.end());
  reverse(rs.begin(), rs.end());
  if(s == rs) {
    cout << 0 << endl;
  } else if(t != rt) {
    cout << -1 << endl;
  } else {
    string u;
    int ans = 0;
    if(m % 2 == 1) {
      for(int i = 0; i < m / 2; i++) {
        int l = num[(m + 1) / 2 - i - 1] - num[(m + 1) / 2 - i - 2];
        int r = num[(m + 1) / 2 + i] - num[(m + 1) / 2 + i - 1];
        ans += abs(l - r);
      }
    } else {
      for(int i = 0; i < m / 2 - 1; i++) {
        int l = num[m / 2 - i - 1] - num[m / 2 - i - 2];
        int r = num[m / 2 + i + 1] - num[m / 2 + i];
        ans += abs(l - r);
      }
    }
    ans += abs((n - num[m - 1] - 1) - num[0]);
    cout << ans << endl;
  }

  return 0;
}