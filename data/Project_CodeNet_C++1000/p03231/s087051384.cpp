#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;

long long gcd(long long x, long long y) {
  return y ? gcd(y, x % y) : x;
}
long long lcm(long long x, long long y) {
  return x/gcd(x, y)*y;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(20) << fixed;

  long long n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;

  long long a = n/gcd(n, m);
  long long b = m/gcd(n, m);

  rep(i, gcd(n, m)) {
    if (s[i*a] != t[i*b]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << lcm(n, m) << endl;

  return 0;
}
