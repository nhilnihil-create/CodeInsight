#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
// pll pp; -> (pp.first,pp.second)
// vector<vl> pp(n,vl(2)); sort(pp.begin(),pp.end(),[](vl a,vl b){return a[0]<b[0];});

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define RREP(i,n) for(ll (i)=(n)-1;(i)>=0;(i)--)
#define DEBUG(x) cout << #x << ": " << x << endl

ll MOD = 1000000000 + 7;
ll a[100001];
ll e[100001];

ll modpow(ll x,ll n){
  if(n==1) return x;
  ll ret = modpow(x*x%MOD,n/2);
  if(n&1) ret *= x;
  return ret%MOD;
}

int main() {
  ll n;
  ll comb = 1;
  cin >> n;
  REP(i,n){
    cin >> a[i];
    e[i] = modpow(i+1,MOD-2);
    //cout << "modpow(" << i+1 << ") = " << e[i] << endl;
    if(i>0) e[i] += e[i-1];
    comb = comb*(i+1)%MOD;
  }
  //REP(i,n) cout << e[i] << endl;

  ll ans=0;
  //DEBUG(comb);
  REP(i,n){
    ll ef = e[i] + e[n-1-i] - 1;
    //cout << "i:" << i << ",ef:" << ef << endl;
    ef %= MOD;
    ans += a[i]*ef%MOD;
    ans %= MOD;
  }
  ans = ans * comb % MOD;

  cout << ans << endl;
  return 0;
}
