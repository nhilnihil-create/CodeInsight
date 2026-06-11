#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 998244353;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;
vector<ll> F(3e5+1);
const int MAX = 510000;
const ll MOD = 998244353;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
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
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(20);
    COMinit();
    ll N,A,B,K;
    ll ans = 0;
    cin >> N >> A >> B >> K;
    for(int i=0;i<=N;i++){
        ll sum = A*i;
        ll left = K - sum;
        if(left%B!=0)continue;
        if(left/B>N)continue;
        //N個のうちi個をAで塗る
        //N個のうちJ個をBで塗る
        ans += COM(N,i)*COM(N,left/B);
        ans %= mod;
    }
    cout << ans << endl;
}