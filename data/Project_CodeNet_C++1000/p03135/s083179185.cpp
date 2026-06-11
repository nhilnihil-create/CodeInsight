#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int t, x;
  cin >> t >> x;
  double ans = (double)t/x;
  cout << fixed << setprecision(5) << ans << endl;
  return 0;
}
