#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ll n,k;
  cin>>n>>k;
  vll x(n);
  int zero=inf;
  rep(i,0,n) {
    cin>>x[i];
    if(zero==inf &&x[i]>=0){
      zero=i;
    }
  }
  if(zero==inf) zero=n-1;
  ll ans=inf;
  rep(i,0,k){
    if(zero-k+i+1>=0 && zero+i<n){
      if(x[zero+i-k+1]<0 && 0 <x[zero+i]){
            ll d=min(abs(x[zero-k+i+1]),abs(x[zero+i]));
            ll cnt=0;
            cnt+=d+abs(x[zero-k+i+1])+abs(x[zero+i]);
            ans=min(ans,cnt);
      }
      else {
       
        ll cnt=0;
        cnt+=max(abs(x[zero-k+i+1]),abs(x[zero+i]));
        ans=min(ans,cnt);
        
      }
     // cout<<ans<<endl;
    }
  }
  cout<<ans<<endl;
}
//k通り調べる　絶対値の小さい方から 0の位置