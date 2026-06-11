#include <bits/stdc++.h>
#define ft first
#define sc second
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



int main() {
  ll N, K;
  cin >> N >> K;
  ll i, j;
  ll a[MAX];
  ll f[50]={};
  
  for(i=0; i<N; i++) {
    cin >> a[i];
    
    for(j=0; j<44; j++) {
      if(1&(a[i]>>j)) f[j]--;
      else f[j]++;
    }
  }
  
  for(i=0; i<44; i++) {
    if(f[i]>0) f[i]=1;
    else f[i]=0;
  }
  
  ll ans=0;
  for(i=0; i<N; i++) {
    ans+=K^a[i];
  }
  
  for(i=0; i<44; i++) {
    if((1&(K>>i))==0) continue;
    ll mask=(K>>(i+1))<<(i+1);
    for(j=0; j<i; j++) {
      if(f[j])
        mask+=1LL<<j;
    }
    
    ll t=0;
    for(j=0; j<N; j++) {
      t+=mask^a[j];
    }
    
    chmax(ans, t);
  }
  
  pt(ans);
  
}



