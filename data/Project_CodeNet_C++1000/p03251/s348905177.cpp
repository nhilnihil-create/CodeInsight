#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);


int main() {
  int n, m, X, Y;
  cin >> n >> m >> X >> Y;
  vector<int> x(n);
  rep(i,n) cin >> x[i];
  vector<int> y(m);
  rep(i,m) cin >> y[i];
  bool ok;
  for(int i = X+1; i < Y; ++i){
    ok = true;
    rep(j,n){
      if(x[j]>=i){
        ok=false;
        break;
      }
    }
    rep(k,m){
      if(y[k]<i){
        ok=false;
        break;
      }
    }
    if(ok) break;
  }
  if(ok) cout << "No War" << endl;
  else cout << "War" << endl;
  return 0;
}