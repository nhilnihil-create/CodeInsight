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




int main(void) {
  ll N, K;
  cin >> N >> K;
  P su[MAX];
  ll i;
  
  for(i=0; i<N; i++) {
    cin >> su[i].second >> su[i].first;
    su[i].second--;
  }
  sort(su, su+N);
  reverse(su, su+N);
  
  ll ans=0;
  ll clr=0;
  ll cnt[MAX]={};
  for(i=0; i<K; i++) {
    cnt[su[i].second]++;
    ans+=su[i].first;
    
    if(cnt[su[i].second]==1) clr++;
  }
  ans+=clr*clr;
  
  ll t=ans-clr*clr;
  ll k=K-1;
  
  for(i=K; i<N; i++) {
    
    if(cnt[su[i].second]) continue;
    
    while(k>=0 && cnt[su[k].second]==1) k--;
    
    if(k<0) break;
    
    cnt[su[k].second]--;
    t-=su[k].first;
    k--;
    
    cnt[su[i].second]++;
    t+=su[i].first;
    clr++;
    
    chmax(ans, t+clr*clr);
  }
  
  pt(ans);
  
}


