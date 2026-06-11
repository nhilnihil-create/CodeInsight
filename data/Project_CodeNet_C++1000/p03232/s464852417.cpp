#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e18;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    ll N;
    cin >> N;
    ll A[N];
    rep(i, N) cin >> A[i];
    ll n = N, m = MOD, inv[n+1];
    rep2(i, 1, n){
        inv[i] = 1;
        ll e[31];
        e[0] = i;
        rep2(j, 1, 30) e[j] = (e[j-1]*e[j-1]) % m;
        ll k = m-2;
        int cnt = 0;
        while(k > 0){
            if(k % 2 == 1) inv[i] *= e[cnt], inv[i] %= m;
            k /= 2;
            cnt++;
        }
    }
    ll fac = 1;
    rep2(i, 1, N){fac *= i; fac %= MOD;}
    ll p[N];
    rep(i, N){p[i] = (fac*inv[i+1])%MOD;}
    ll sum[N];
    sum[0] = p[0];
    rep2(i, 1, N-1){sum[i] = (sum[i-1]+p[i])%MOD;}
    ll ans = 0;
    rep(i, N){
        ll s = sum[i]+sum[N-1-i]+(MOD-sum[0]);
        s %= MOD;
        ans += (A[i]*s)%MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}