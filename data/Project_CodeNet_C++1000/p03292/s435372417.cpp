#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int a, b, c;
  cin >> a >> b >> c;
  int d, e, f;
  d = abs(a-b);
  e = abs(b-c);
  f = abs(c-a);

  int ans = min({d+e, e+f,f+d});
  cout << ans << endl;
  return 0;
}
