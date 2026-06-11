#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>
#include <cstdint>



#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rrep(i, n) for(ll i = (ll)(n-1); i >= 0; i--)
#define repi(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rrepi(i,a,b) for(ll i=(ll)(b-1);i>=(ll)(a);i--)

#define all(x) (x).begin(),(x).end()

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,k;cin>>n>>k;
  vector<ll>a(n),sa(n+1);
  rep(i,n)cin>>a[i];
  rep(i,n){
    sa[i+1]=sa[i]+a[i];
  }
  vector<ll>lr;
  rep(i,n)repi(j,i+1,n+1){
    lr.push_back(sa[j]-sa[i]);
  }
  sort(all(lr),greater<ll>());
  ll l=lr.size();
  rrep(i,63){
    ll b=1LL<<i;
    ll cnt=0;
    rep(j,l){
      if(lr[j]&b)cnt++;
    }
    if(cnt>=k){
      rep(j,l){
        if(lr[j]&b){}
        else lr[j]=0;
      }
    }
    else{
      rep(j,l){
        lr[j]|=b;
        lr[j]^=b;
      }
    }
  }
  sort(all(lr),greater<ll>());
  ll res=lr[0];
  rep(i,k){
    res&=lr[i];
  }
  cout<<res<<endl;
  return 0;

}
