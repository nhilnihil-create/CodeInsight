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
  
  for(i=1; i<=3500; i++) {
    for(j=1; j<=3500; j++) {
      ll n=N*i*j;
      ll d=4*i*j-N*i-N*j;
      
      if(d<=0) continue;
      
      if(n%d==0) {
        pt(i<<" "<<j<<" "<<n/d);
        return 0;
      }
      
    }
  }
  
  
  
}






