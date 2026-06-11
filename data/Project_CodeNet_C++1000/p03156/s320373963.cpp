#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define DUMP(x)  cout << #x << " = " << (x) << endl;
#define FOR(i, m, n) for(ll i = m; i < n; i++)
#define IFOR(i, m, n) for(ll i = n - 1; i >= m; i-- )
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FOREACH(x,a) for(auto& (x) : (a) )
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) ll(x.size())

int main(){
  ll n,a,b; cin >> n >> a >> b;
  vector<ll> cnt(3,0);
  REP(i,n){
    ll p; cin >> p;
    if(p<=a) cnt[0]++;
    else if(p<=b) cnt[1]++;
    else cnt[2]++;
  }
  ll ans = 1e18;
  REP(i,3) ans = min(ans, cnt[i]);
  cout << ans << endl;
}