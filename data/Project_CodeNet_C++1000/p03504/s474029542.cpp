#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MOD=1e9+7;
static const ll MAX=101010;

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/

ll f[33][MAX];

int main(void) {
  ll i, j, k, l;
  
  ll N;
  cin >> N;
  ll C;
  cin >> C;
  
  for(i=0; i<N; i++) {
    ll s, t, c;
    cin >> s >> t >> c;
    t++; c--;
    f[c][s]++;
    f[c][t]--;
  }
  
  for(i=0; i<C; i++) {
    for(j=1; j<MAX; j++) f[i][j]+=f[i][j-1];
    for(j=1; j<MAX; j++) if(f[i][j]>=2) f[i][j]=1;
  }
  
  ll ans=0;
  for(j=1; j<MAX; j++) {
    ll t=0;
    for(i=0; i<C; i++) t+=f[i][j];
    chmax(ans, t);
  }
  
  pt(ans);
  
}


