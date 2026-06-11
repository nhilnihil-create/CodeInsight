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
  int n;
  cin >> n;
  vector<string> s(n);
  int a = 0, b = 0, ab = 0;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
    if(*s[i].begin() == 'B' && *s[i].rbegin() == 'A') {
      ab++;
    } else if(*s[i].begin() == 'B') {
      b++;
    } else if(*s[i].rbegin() == 'A') {
      a++;
    }
    for(int j = 0; j < s[i].length() - 1; j++) {
      if(s[i][j] == 'A' && s[i][j + 1] == 'B') {
        ans++;
      }
    }
  }
  if(ab >= 1) {
    ans += ab - 1;
    if(a >= 1) {
      ans++;
      a--;
    }
    if(b >= 1) {
      ans++;
      b--;
    }
  }
  ans += min(a, b);
  cout << ans << endl;
  return 0;
}