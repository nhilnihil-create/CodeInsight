#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  vector<int> a(3);
  REP(i,3) cin >> a[i];
  sort(a.rbegin(), a.rend());
  int ans = 10*a[0] + a[1] + a[2];
  cout << ans << endl;
  return 0;
}
