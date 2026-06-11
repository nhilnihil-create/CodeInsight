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
  ll N;
  cin >> N;
  ll i;
  ll a[MAX*2];
  
  for(i=0; i<N; i++) {
    cin >> a[i];
  }
  a[N]=a[N-1];
  
  if(a[0]) {
    pt(-1);
    return 0;
  }
  
  for(i=0; i<N-1; i++) {
    if(a[i+1]-a[i]>1) {
      pt(-1);
      return 0;
    }
  }
  
  ll ans=0;
  ll t=0;
  for(i=N-1; i>=1; i--) {
    if(a[i]>=a[i+1]) {
      ans+=a[i];
    }
  }
  
  pt(ans);
}
