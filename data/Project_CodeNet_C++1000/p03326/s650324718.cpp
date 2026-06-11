#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n,m;
  cin >> n >> m;
  vector<vector<ll>> v(n, vector<ll>(3));
  REP(i,n) REP(j,3) cin >> v[i][j];
  
  ll ans = 0;
  REP(bit, (1<<3)){
    vector<ll> sum(n, 0);
    
    REP(d,3){
      if(bit & (1<<d)) REP(i,n) sum[i] += v[i][d];
      else REP(i,n) sum[i] -= v[i][d];
    } 
    sort(ALL(sum), greater<ll>());
    ll tmp = 0;
    REP(i,m) tmp += sum[i];
    ans = max(ans, tmp);
  }
  cout << ans << '\n';
  return 0;
}