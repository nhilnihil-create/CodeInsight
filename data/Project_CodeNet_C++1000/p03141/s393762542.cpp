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
  ll i, j;
  
  P p[MAX];
  for(i=0; i<N; i++) {
    ll a, b;
    cin >> a >> b;
    p[i]={a+b, a};
  }
  sort(p, p+N);
  reverse(p, p+N);
  
  ll ans=0;
  for(i=0; i<N; i++) {
    if((i&1)==0) ans+=p[i].second;
    else ans-=p[i].first-p[i].second;
  }
  
  pt(ans);
}
