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
  vector<string> s(3);
  ll N; cin >> N;
  REP(i,3) cin >> s[i];
  ll ans = 0;
  REP(i,N){
    if(s[0][i] == s[1][i] && s[1][i] == s[2][i]) continue;
    if(s[0][i] == s[1][i] || s[1][i] == s[2][i] 
      || s[2][i] == s[0][i]) ans++;
    else ans += 2;
  }
  cout << ans << endl;
}