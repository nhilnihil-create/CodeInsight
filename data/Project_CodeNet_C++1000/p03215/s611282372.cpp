#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;
static const ll LOGN=55;


int main(void) {
  ll N, K;
  cin >> N >> K;
  ll a[1111];
  ll s[1111]={};
  ll i, j;
  
  for(i=1; i<=N; i++) {
    cin >> a[i];
    s[i]=a[i]+s[i-1];
  }
  
  vector<ll> v;
  ll cnt[44]={};
  for(i=0; i<N; i++) {
    for(j=i+1; j<=N; j++) {
      ll t=s[j]-s[i];
      v.push_back(t);
      ll bit=0;
      while(t>0) {
        if(t&1) cnt[bit]++;
        bit++;
        t>>=1;
      }
    }
  }
  
  ll f[MAX*10];
  memset(f, 1, sizeof(f));
  ll ans=0;
  for(ll b=40; b>=0; b--) {
    if(cnt[b]>=K) {
      ans+=pow(2, b);
      
      for(i=0; i<v.size(); i++) {
        if(!f[i]) continue;
        
        if(v[i]>>b&1) continue;
          
        f[i]=0;
        ll t=v[i];
        ll bit=0;
        while(t>0) {
          if(t&1) cnt[bit]--;
          bit++;
          t>>=1;
        }
        
      }
    }
  }
  
  pt(ans);
}




