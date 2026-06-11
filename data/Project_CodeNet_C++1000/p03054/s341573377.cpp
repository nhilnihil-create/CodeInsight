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
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 1000000007;
long long INF = 1000000000000000; //10^15
typedef long long ll;
typedef unsigned long long ull;

int main(void) {

  int h, w, n, sr, sc;
  string s, t;
  int cs[4] = {}, ct[4] = {};
  cin >> h >> w >> n;
  cin >> sr >> sc;
  cin >> s >> t;

  int x;
  x = sc;
  //s-l t-r
  rep(i, n) {
    if (s[i] == 'L') x--;
    if (x < 1) {
      cout << "NO\n";
      return 0;
    }
    if (t[i] == 'R' && x < w) x++;
  }
  
  //s-r t-l
  x = sc;
  rep(i, n) {
    if (s[i] == 'R') x++;
    if (x > w) {
      cout << "NO\n";
      return 0;
    }
    if (t[i] == 'L' && x > 1) x--;
  }

  //s-u t-d
  x = sr;
  rep(i, n) {
    if (s[i] == 'U') x--;
    if (x < 1) {
      cout << "NO\n";
      return 0;
    }
    if (t[i] == 'D' && x < h) x++;
  }

  //s-d t-u
  x = sr;
  rep(i, n) {
    if (s[i] == 'D') x++;
    if (x > h) {
      cout << "NO\n";
      return 0;
    }
    if (t[i] == 'U' && x > 1) x--;
  }

  cout << "YES\n";

  return 0;

}
