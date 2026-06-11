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
  ll k, a, b;
  cin >> k >> a >> b;
  
  ll t=a-1;
  ll ans=max(1+k, a+(b-a)*((k-t)/2)+(k-t)%2);
  pt(ans);
  
}






