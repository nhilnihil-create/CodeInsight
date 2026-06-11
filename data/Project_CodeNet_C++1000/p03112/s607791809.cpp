#include <bits/stdc++.h>
#include <string>
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
  
  ll A, B, Q;
  cin >> A >> B >> Q;
  ll s[MAX], t[MAX];
  
  for(i=1; i<=A; i++) cin >> s[i]; s[0]=-INF; s[A+1]=INF;
  for(i=1; i<=B; i++) cin >> t[i]; t[0]=-INF; t[B+1]=INF;
  
  for(ll _=0; _<Q; _++) {
    ll x;
    cin >> x;
    
    ll ps=lower_bound(s, s+A+2, x)-s;
    ll pt=lower_bound(t, t+B+2, x)-t;
    
    ll d[]={s[ps]-x, t[pt]-x, x-s[ps-1], x-t[pt-1]};
    
    ll t1=min(max(d[0], d[1]), max(d[2], d[3]));
    ll t2=min(d[0]+d[3]+min(d[0], d[3]), d[1]+d[2]+min(d[1], d[2]));
    
    pt(min(t1, t2));
  }
  
}

