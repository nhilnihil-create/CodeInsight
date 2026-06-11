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
  ll a[MAX], b[MAX], c[MAX], d[MAX];
  ll i, j;
  ll sa=0, sb=0;
  
  for(i=0; i<N; i++) cin >> a[i];
  for(i=0; i<N; i++) cin >> b[i];
  
  for(i=0; i<N; i++) {
    c[i]=a[i]-b[i];
    d[i]=c[i];
  }
  sort(c, c+N);
  sort(d, d+N);
  
  ll l=0, r=N-1;
  while(l<r && d[l]<0 && d[r]>0) {
    
    if(d[l]+d[r]==0) {
      d[l]=d[r]=0;
      l++; r--;
    }else if(d[l]+d[r]>0) {
      d[r]+=d[l];
      d[l]=0;
      l++;
    }else {
      d[l]+=d[r];
      d[r]=0;
      r--;
    }
    
  }
  
  ll ans=0;
  for(i=0; i<N; i++) {
    if(d[i]<0) {
      pt(-1);
      return 0;
    }
    
    if(c[i]!=d[i]) ans++;
    
  }
  
  pt(ans);
}



