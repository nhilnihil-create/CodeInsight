#include <bits/stdc++.h>
#define ft first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=1e5+7;
static const ll MOD=1e9+7;
ll max(ll a, ll b) {return a>b?a:b;}
ll min(ll a, ll b) {return a<b?a:b;}

ll moP(ll x, ll n) {
  ll res=1;
  while(n>0) {
    if(n&1) moC(res, *, x);
    moC(x, *, x);
    n>>=1;
  }
  return res;
}

int main(void) {
  ll N;
  cin >> N;
  ll i;
  ll Nfa=1;
  ll s[MAX]={};
  
  for(i=1; i<=N; i++) moC(Nfa, *, i);
  
  for(i=1; i<=N; i++) {
    s[i]=(s[i-1]+moP(i, MOD-2))%MOD; // 1/i の累積和
  }
  
  ll ans=0;
  for(i=1; i<=N; i++) {
    ll a;
    cin >> a;
    moC(ans, +, (s[i]+s[N-i+1]-s[1]+MOD)*Nfa%MOD*a%MOD);
  }
  
  pt(ans);
}










