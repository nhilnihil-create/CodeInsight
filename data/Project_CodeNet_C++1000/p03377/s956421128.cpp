#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);


int main() {
  int a, b, x;
  cin >> a >> b >> x;
  bool ok = true;

  if(a > x) ok = false;
  if(x > a + b) ok = false;

  if(ok) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
