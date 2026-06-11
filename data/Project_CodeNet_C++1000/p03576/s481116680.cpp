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



#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,k;cin>>n>>k;
  vector<ll>x(n),y(n);
  rep(i,n)
  {
    cin>>x[i]>>y[i];
  }
  auto yy=y,xx=x;
  sort(all(yy));
  sort(all(xx));
  ll res=5e18;
  rep(ixl,n)repi(ixh,ixl,n)rep(iyl,n)
  {
    ll ok=n;
    ll ng=iyl-1;
    while(ok-ng>1)
    {
      ll nn=(ok+ng)/2;
      bool check=[&](ll a){
        ll cnt=0;
        if(a<0)return false;
        rep(i,n)
        {
          if(y[i]<=yy[a]&&xx[ixl]<=x[i]&&xx[ixh]>=x[i]&&y[i]>=yy[iyl])cnt++;
        }
        return cnt>=k;
      }(nn);
      if(check)ok=nn;
      else ng=nn;
    }
    if(ok==n)continue;
    if(yy[ok]-yy[iyl]<0)continue;
    chmin(res,(ll)(xx[ixh]-xx[ixl])*(yy[ok]-yy[iyl]));
  //  cout<<ok<<res<<endl;
  }
  cout<<res<<endl;

  return 0;

}
