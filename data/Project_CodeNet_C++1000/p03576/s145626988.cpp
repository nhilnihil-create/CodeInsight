#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=2e9+7;
const ll longinf=1LL<<62;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=100010;
const ll mod=1e9+7;

int main(){
  int n,k; cin >> n >> k;
  vector<ll> x(n),y(n);
  vector<ll> xx,yy;
  rep(i,n){
    cin >> x[i] >> y[i];
    xx.push_back(x[i]);
    yy.push_back(y[i]);
  }
  sort(xx.begin(),xx.end());
  sort(yy.begin(),yy.end());

  ll ans=longinf;
  rep(i,n)REP(j,i+1,n)rep(l,n)REP(m,l+1,n){
    int cnt=0;
    rep(t,n){
      if(xx[i]<=x[t]&&x[t]<=xx[j]&&yy[l]<=y[t]&&y[t]<=yy[m]){ cnt++; }
    }
    if(cnt>=k)ans=min(ans,(xx[j]-xx[i])*(yy[m]-yy[l]));  
  }
  
  cout << ans << endl;
  return 0;                                                 
}