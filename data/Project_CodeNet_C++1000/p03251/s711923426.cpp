#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int n,m,X,Y; cin >> n >> m >> X >> Y;
  vector<int> x(n),y(m);
  rep(i,n) cin >> x[i];
  rep(i,m) cin >> y[i];

  /*  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  */
  
  for(int z = X+1;z<=Y;z++){
    bool war_x = false,war_y = false;
    rep(i,n) if(x[i]>=z) war_x = true;
    rep(i,m) if(y[i]<z) war_y = true;
    if(!(war_x) && !(war_y)){
      cout << "No War" << endl;
      return 0;
    }
  }

  cout << "War" << endl;
  
  return 0;
}
