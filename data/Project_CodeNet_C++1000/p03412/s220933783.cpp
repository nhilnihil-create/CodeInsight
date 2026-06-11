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
  ll MAX_DIGIT = 29;
  vector<ll> a(N), b(N);
  REP(i,N) cin >> a[i];
  REP(i,N) cin >> b[i];
  ll ans = 0;
  //k-bit目を特定する k:0-indexed
  IREP(k,MAX_DIGIT){
    // a[i]+b[j]のうち，k-bit目が1となる個数の偶奇
    ll parity = 0;
    // 2**(k+1)でmodとってOK
    REP(i,N) {
      a[i] %= 1<<(k+1);
      b[i] %= 1<<(k+1);
    }
    sort(ALL(b));
    ll T = 1<<k;
    // [T-a_i,2T-a_i), [3T-a_i,4T-a_i)の範囲にあるb_jをカウント
    REP(i,N){
      parity += lower_bound(ALL(b),2*T-a[i]) - upper_bound(ALL(b),T-a[i]-1);
      parity += lower_bound(ALL(b),4*T-a[i]) - upper_bound(ALL(b),3*T-a[i]-1);
    }
    parity %= 2;
    ans += parity * (1<<k);
  }
  cout << ans << endl;
}