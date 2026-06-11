#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define pb push_back
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for(int i=(a)-1;i>=(b);i++)
#define RREP(i, n) FOR(i, n, 0);
 
int gcd(int a, int b) {
  if(b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
 
signed main () {
  cin.tie(0);
  cout << setprecision(10);
 
  int t; cin >> t;
  REP(i, t) {
    int a, b, c, d; cin >> a >> b >> c >> d;
 
    if(a < b || b > d) {
      cout << "No" << endl;
      continue;
    }
 
    if(c >= b) {
      cout << "Yes" << endl;
      continue;
    }
 
    int g = gcd(b, d);
    int ma = b - g + (a % g);
 
    if(ma > c) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
}