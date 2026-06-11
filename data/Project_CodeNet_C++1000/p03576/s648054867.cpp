#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=200010;
const ll mod=1e9+7;

int main() {
  int n,k;
  cin >> n >> k;
  vector<ll> x(n),y(n);
  rep(i,n) cin >> x[i] >> y[i];
  auto a = x, b = y;
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());

  ll ans = longinf*4;
  rep(i,n)REP(j,i+1,n)rep(p,n)REP(q,p+1,n){
    int cnt=0;
    rep(k,n)if(a[i]<=x[k] && x[k]<=a[j] && b[p]<=y[k] && y[k]<= b[q]) cnt++;
    if(cnt >= k){ 
      ll tmp = (a[j]-a[i])*(b[q]-b[p]);
      ans = min(ans, tmp);
    }
  }
  cout << ans << endl;
  return 0;
}