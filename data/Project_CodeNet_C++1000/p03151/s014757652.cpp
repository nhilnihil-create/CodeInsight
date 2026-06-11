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
  ll a[MAX], b[MAX], c[MAX];
  ll i, j;
  ll sa=0, sb=0;
  
  for(i=0; i<N; i++) cin >> a[i];
  for(i=0; i<N; i++) cin >> b[i];
  
  for(i=0; i<N; i++) c[i]=a[i]-b[i];
  sort(c, c+N);
  
  ll s=0;
  ll ans=0;
  for(i=0; i<N; i++) {
    if(c[i]>=0) break;
    s+=c[i];
    ans++;
  }
  
  for(i=N-1; i>=0; i--) {
    if(s>=0) {
      pt(ans);
      return 0;
    }
    
    s+=c[i];
    ans++;
  }
  
  pt(-1);
  
}



