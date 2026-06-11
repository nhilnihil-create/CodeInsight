#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)

#define FILE_IN "pviz.in"
#define FILE_OUT "pviz.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define pow2(x) (ll(1)<<x)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define endl "\n"

#define ALL(A) (A).begin(), (A).end()
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

 

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
 
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    COMinit();
 
    ll N,A,B,K;
    cin >> N >> A >> B >> K;
    ll ans = 0;
    for(ll i=0;i<=N;i++){
        ll np = A*i;
        if(np>K)break;
        if( (K-np) % B == 0 ){
            ans += COM(N,i) * COM(N,(K-np)/B);
            ans %= MOD;
        }
    }
    cout << ans << endl;
}