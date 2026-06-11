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
  
  ll cnt=0;
  vector<ll> g[111];
  for(i=1; i<=N; i++) {
    for(j=i+1; j<=N; j++) {
      if(N%2==0 && i+j==N+1) continue;
      if(N%2==1 && i+j==N)   continue;
      
      g[i].push_back(j);
      cnt++;
    }
  }
  
  pt(cnt);
  for(i=1; i<=N; i++) {
    for(j=0; j<g[i].size(); j++) {
      pt(i<<" "<<g[i][j]);
    }
  }
  
  
}
