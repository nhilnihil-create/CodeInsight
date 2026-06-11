#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
 
 
 
int main(){
  int n, m;
  cin >> n >> m;
  vector<int> L(m);
  vector<int> R(m);
  REP(i,m){
    int l, r;
    cin >> l >> r;
    L[i] = l;
    R[i] = r;
  }
 
  int lmax = 0;
  int rmin = 100005;
  REP(i,m){
    lmax = max(lmax, L[i]);
    rmin = min(rmin, R[i]);
  }
 
  int ans;
  if(rmin - lmax < 0) ans = 0;
  else ans = rmin - lmax + 1;
  cout  << ans << endl;
  return 0;
}