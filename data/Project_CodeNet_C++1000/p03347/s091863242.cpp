#include <bits/stdc++.h>
#include <string>
#define ft first
#define sc second
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) (a)=max(a, b);
#define chmin(a, b) (a)=min(a, b);
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
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
  ll a[MAX*2];
  
  for(i=0; i<N; i++) cin >> a[i];
  
  ll f=0;
  if(a[0]) f=1;
  for(i=0; i<N-1; i++) {
    if(a[i+1]-a[i]>1) f=1;
  }
  
  if(f) {pt(-1); return 0;}
  
  ll ans=0;
  for(i=1; i<N; i++) {
    if(a[i-1]+1==a[i]) ans++;
    else ans+=a[i];
    
  }
  
  pt(ans);
}

