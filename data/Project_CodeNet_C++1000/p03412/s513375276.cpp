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
  ll n; cin>>n;
  vi a(n); REP(i,n) cin>>a[i];
  vi b(n); REP(i,n) cin>>b[i];
  ll ans=0;
  REP(i,30) {
    vi ac=a,bc=b;
    REP(j,n) ac[j]%=(1ll<<(i+1));
    REP(j,n) bc[j]%=(1ll<<(i+1));
    sort(bc.begin(),bc.end());
    ll cnt=0;
    REP(j,n) {
      ll s1=(1ll<<i)-ac[j]%(1ll<<(i+1));
      ll t1=(1ll<<(i+1))-ac[j]%(1ll<<(i+1));
      ll s2=(1ll<<(i+1))+(1ll<<i)-ac[j]%(1ll<<(i+1));
      ll t2=(1ll<<(i+2))-ac[j]%(1ll<<(i+1));
      cnt+=lower_bound(bc.begin(),bc.end(),t1)-lower_bound(bc.begin(),bc.end(),s1);
      cnt+=lower_bound(bc.begin(),bc.end(),t2)-lower_bound(bc.begin(),bc.end(),s2);
    }
    if(cnt%2) ans+=(1ll<<i);
  }
  cout<<ans<<endl;
}
