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
  string s; cin >> s;
  ll n = SZ(s);
  ll ans = n;
  REP(i,n-1){
    if(s[i] == s[i+1]) continue;
    ans = min(ans, max(i+1,n-(i+1)));
  }
  cout << ans << endl;
}
