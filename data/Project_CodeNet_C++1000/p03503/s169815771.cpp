#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using st=string;
using ch=char;
typedef pair<ll,ll> P;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<P> vP;
typedef vector<ch> vc;
typedef vector<vc> vvc;
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) FOR(i,0,n)
#define ROF(i,a,b) for(ll i=a;i>=b;i--)
#define per(i,a) ROF(i,a,0)
const ll MOD=1000000007;
const ll MOD2=998244353;
const ld PI=acos(-1);
const ll INF=1e18;
st abc="abcdefghijklmnopqrstuvwxyz";
st ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
struct edge{ll to,cost;};

int main() {
  ll N;
  cin >> N;
  vvl F(N,vl(10));
  rep(i,N){
    rep(j,10){
      cin >> F[i][j];
    }
  }
  vvl p(N,vl(11));
  rep(i,N){
    rep(j,11){
      cin >> p[i][j];
    }
  }
  ll ans=-INF;
  FOR(i,1,1<<10){
    vl cnt(N,0);
    rep(j,N){
      rep(k,10){
        if((i>>k)%2==1){
          cnt[j]+=F[j][k];
        }
      }
    }
    ll d=0;
    rep(j,N){
      d+=p[j][cnt[j]];
    }
    ans=max(ans,d);
  }
  cout << ans << endl;
}