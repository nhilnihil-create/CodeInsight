#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, n) for (int i = (int)(n); i > 0; i++)

using ll=long long;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<int> X(n),Y(m);
  rep(i,n) cin >> X[i];
  rep(i,m) cin >> Y[i];
  int ans = 0;
  for(int z = x+1; z<=y ; z++) {
    bool J = 1;
    rep(j,n) if(!(z>X[j])) J = 0;
    rep(j,m) if(!(z<=Y[j])) J = 0;
    if(J) ans++;
  }
  if(ans) cout << "No War" << endl;
  else cout << "War" << endl;
  
}