#include <bits/stdc++.h>
using namespace std;;
#define ll long long
#define REP(i, n) for(ll i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define INF 1<<30
#define LINF 1LL<<62
#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
const ll MOD = 998244353;
 
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  COMinit();
   ll n,a,b,k; cin >> n >> a >> b >> k;
   ll ans = 0;
   REP(i,n+1){
       if(k<b*i)break;
       if((k-b*i) %a == 0 && (k-b*i) / a <= n){
           ll cnta = (k-b*i) / a;
           ll cntb = i;
           ans += COM(n,cnta) %MOD * COM(n,cntb);
           ans %= MOD;
       }
   }
   cout << ans << endl;


}