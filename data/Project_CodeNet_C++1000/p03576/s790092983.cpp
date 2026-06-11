#include<iostream>
#include <cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=(1LL<<63) - 600;
const ll mod=1e9+7 ;

int main(){
  int N, K; cin >> N >> K; ll x[N], y[N];
  rep(i, N){
    cin >> x[i] >> y[i];
  }
  ll ans = longinf;
  if(K==2){
    rep(i, N){
      rep(j, N){
        if(i==j) continue;
        ans = min(abs(x[i]-x[j])*abs(y[i]-y[j]), ans);
      }
    }
    cout << ans << endl; return 0;
  }
  if(K==3){
    rep(i, N){
    rep(j, N){
      if(i==j) continue;
      rep(k, N){
        if(i==k || j==k) continue;
        ll R = max({x[i], x[j], x[k]});
        ll L = min({x[i], x[j], x[k]});
        ll U = max({y[i], y[j], y[k]});
        ll D = min({y[i], y[j], y[k]});
        ans = min(ans, (R-L)*(U-D));
      }
    }
    }
    cout << ans << endl; return 0;
  }
  rep(i, N){
    rep(j, N){
      if(i==j) continue;
      rep(k, N){
        if(i==k || j==k) continue;
        rep(l, N){
          if(i==l || j==l || k==l) continue;
          ll R = max({x[i], x[j], x[k], x[l]});
          ll L = min({x[i], x[j], x[k], x[l]});
          ll U = max({y[i], y[j], y[k], y[l]});
          ll D = min({y[i], y[j], y[k], y[l]});
          int cnt = 0;
          rep(m, N){
            if(x[m]>=L&&x[m]<=R&&y[m]<=U&&y[m]>=D)
              cnt++;
          }
          if(cnt>=K) ans = min(ans, (R-L)*(U-D));
        }
      }
    }
  }
  cout << ans << endl;
}
