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

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/


int main(void) {
  ll i, j, k;
  ll N;
  cin >> N;
  ll cnt[15]={};
  
  cnt[0]++; //Takahashi-kun
  for(i=0; i<N; i++) { ll t; cin >> t; cnt[t]++;}
  
  ll f=0;
  for(i=1; i<=11; i++) if(cnt[i]>=3) f=1;
  if(cnt[0]>=2 || cnt[12]>=2) f=1;
  if(f) {pt(0); return 0;}
  
  
  ll ans=0;
  for(ll S=0; S<1<<11; S++) {
    vector<ll> l, r;
    for(i=1; i<=11; i++) {
      if(cnt[i]==1) {
        if(S>>i&1) l.push_back(i);
        else r.push_back(i);
      }else if(cnt[i]==2) {
        l.push_back(i);
        r.push_back(i);
      }
    }
    if(cnt[12]) l.push_back(12);
    
    ll t=INF;
    ll LS=l.size(), RS=r.size();
    if(LS) chmin(t, l[0]-0);
    for(i=0; i<LS-1; i++) chmin(t, l[i+1]-l[i]);
    
    if(RS) chmin(t, r[0]-0);
    for(i=0; i<RS-1; i++) chmin(t, r[i+1]-r[i]);
    
    if(LS&&RS) chmin(t, 24-(l[LS-1]+r[RS-1]));
    
    chmax(ans, t);
    
  }
  
  
  pt(ans);
  
}

