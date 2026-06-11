#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=(int)(a); i!=(int)(b); i++)
#define RFOR(i, a, b) for(int i=(int)(a); i!=(int)(b); i--)
#define REP(i, n) FOR(i, 0, n)
using namespace std;
using ll = long long;

constexpr int lim = 1e5;

ll n, k;
ll a[lim+1], b[lim+1];

ll allocation(ll c){
  ll ret = 0;
  REP(i, n){
    if((c | a[i]) == c) ret += b[i];
  }

  return ret;
}

ll solve(ll m){
  if(m == -1) return 0;
  if(((k >> m) & 1) == 0){
    return solve(m-1);
  }

  ll t = (1<<m) - 1;
  return max(allocation((k-(1<<m))|t), solve(m-1));
} 

int main(){
  cin >> n >> k;
  REP(i, n) cin >> a[i] >> b[i];

  cout << max(allocation(k), solve(30)) << endl;
    
  return 0;
}
