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

const ll MOD = 1e9+7;
int main(){
  ll N; cin >> N;
  //pos[i] = 色iが直近で出現した位置
  ll MAX = 2e5;
  vector<ll> C(N), dp(N,0), pos(MAX+1,-1);
  dp[0] = 1;
  REP(i,N) cin >> C[i];
  pos[C[0]] = 0;
  FOR(i,1,N){
    if(C[i]==C[i-1] || pos[C[i]]==-1){
      (dp[i] += dp[i-1]) %= MOD;
    }else{
      (dp[i] += (dp[i-1]+dp[pos[C[i]]] )%MOD) %= MOD;
    }
    pos[C[i]] = i;
  }
  cout << dp[N-1] << endl;
}
