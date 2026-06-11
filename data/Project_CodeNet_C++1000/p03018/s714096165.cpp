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
  string s;
  cin >> s;
  ll ans = 0;
  int n = s.length();
  ll a = 0;
  for(int i = 0; i < n; i++) {
    while(s[i] == 'A') {
      a++;
      i++;
    }
    if(i < n - 1) {
      if(s[i] == 'B' && s[i + 1] == 'C' && a > 0) {
        ans += a;
        i++;
      } else if(s[i] == 'C' || s[i] == 'B') {
        a = 0;
      }
    }
  }
  cout << ans << endl;
  return 0;
}