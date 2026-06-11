#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double lb;
#define rep(i,j,n) for (ll i = j; i < (n); i++)
#define repr(i,j,n) for(ll i = j; i >= (n); i--)
#define each(i,mp) for(auto& i:mp)
#define all(x) (x).begin(),(x).end()
#define CLR(mat,f) memset(mat, f, sizeof(mat))
#define IN(a, b, x) (a<=x&&x<b)
#define out(ans) cout << ans << endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef pair<ll,ll>P;
const ll mod=1e9+7;
const ll INF = 1LL<<60;
const ll m=1LL<<32;

int main(){

  ll k,a,b;cin>>k>>a>>b;

  ll money=0;

  if(b-a<=2){
    out(1+k);
  }
  else{
    ll n=k-(a-1);
    if(n<=0){
      out(1+k);
      // out("a");
    }
    else{
      if(n%2){
        out(a+(n/2)*(b-a)+1);
        // out("b");
      }else{
        out(a+(n/2)*(b-a));
        // out("c");
      }
    }
  }

  return 0;
}
