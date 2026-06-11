#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()re


int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  
  int ans = 1e9;
  if (a+b > c*2) {
    if (x > y) {
      for (int numc = y*2; numc <= x*2; numc += 2) {
        ans = min(ans, c*numc + a*(x - numc/2));
      }
    } else {
      for (int numc = x*2; numc <= y*2; numc += 2) {
        ans = min(ans, c*numc + b*(y - numc/2));
      }
    }
  } else {
    ans = a*x +b*y;
  }
  
  cout << ans << endl;
  
}