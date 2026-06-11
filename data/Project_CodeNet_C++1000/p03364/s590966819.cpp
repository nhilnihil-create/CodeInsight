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
  ll N; cin >> N;
  vector<string> s(N);
  REP(i,N) cin >> s[i];
  ll ans = 0;
  REP(a,N) {
    bool ok = true;
    REP(i,N) REP(j,N){
      ll x = (a+i)%N;
      ll y = j%N;
      ll xx = (a+j)%N;
      ll yy =  i%N;
      if(s[x][y] != s[xx][yy]) 
        ok = false;
    }
    if(ok) ans += N;
  }
  cout << ans << endl;
}
