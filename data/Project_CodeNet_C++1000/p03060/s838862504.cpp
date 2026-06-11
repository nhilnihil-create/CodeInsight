#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> c(n);

  REP(i,n) cin >> v[i];
  REP(i,n) cin >> c[i];

  int ans = 0;

  REP(i,n){
    if(v[i] - c[i] > 0) ans += v[i]- c[i];
  }

  cout << ans << endl;

  return 0;
}
