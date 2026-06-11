#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i,n) FOR(i,0,n)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define PB push_back
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<ll,ll> pii;
typedef vector<pii> vpii;
typedef pii point;
using namespace std;
const ll INF = (1ll<<32);
const ll MOD = 1000000007;

int main() {
  ll n,c; cin>>n>>c;
  vi x(n),v(n); REP(i,n) cin>>x[i]>>v[i];
  vi d(n),e(n),f(n),g(n);
  {
    ll vsum=0;
    REP(i,n) {
      vsum+=v[i];
      d[i]=vsum-x[i];
      e[i]=vsum-x[i]*2;
    }
  }
  {
    ll vsum=0;
    for(ll i=n-1;i>=0;i--) {
      vsum+=v[i];
      f[i]=vsum-(c-x[i]);
      g[i]=vsum-2*(c-x[i]);
    }
  }
  vi dm(n),em(n),fm(n),gm(n);
  {
    dm[0]=d[0]; em[0]=e[0];
    FOR(i,1,n) {
      dm[i]=max(dm[i-1],d[i]);
      em[i]=max(em[i-1],e[i]);
    }
  }
  {
    fm[n-1]=f[n-1]; gm[n-1]=g[n-1];
    for(ll i=n-2;i>=0;i--) {
      fm[i]=max(fm[i+1],f[i]);
      gm[i]=max(gm[i+1],g[i]);
    }
  }
  ll ans=max(dm[n-1],fm[0]);
  REP(i,n-1) {
    ans=max(ans,d[i]+gm[i+1]);
    ans=max(ans,e[i]+fm[i+1]);
  }
  cout<<max(0ll,ans)<<endl;
}

// 7565
