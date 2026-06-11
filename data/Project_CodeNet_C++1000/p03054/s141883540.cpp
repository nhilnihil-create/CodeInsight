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



int main(void) {
  ll i, j, k, l;
  
  ll H, W, N;
  cin >> H >> W >> N;
  ll sx, sy;
  cin >> sx >> sy; sx--; sy--;
  string s, t;
  cin >> s >> t;
  
  ll tx, ty;
  
  //上を目指す
  tx=sx;
  for(i=0; i<N; i++) {
    if(s[i]=='U') tx--;
    if(tx<0) { pt("NO"); return 0;}
    if(t[i]=='D' && tx<H-1) tx++;
  }
  
  //下を目指す
  tx=sx;
  for(i=0; i<N; i++) {
    if(s[i]=='D') tx++;
    if(tx>=H) { pt("NO"); return 0;}
    if(t[i]=='U' && tx>0) tx--;
  }
  
  //左を目指す
  ty=sy;
  for(i=0; i<N; i++) {
    if(s[i]=='L') ty--;
    if(ty<0) { pt("NO"); return 0;}
    if(t[i]=='R' && ty<W-1) ty++;
  }
  
  //右を目指す
  ty=sy;
  for(i=0; i<N; i++) {
    if(s[i]=='R') ty++;
    if(ty>=W) { pt("NO"); return 0;}
    if(t[i]=='L' && ty>0) ty--;
  }
  
  pt("YES");
}


