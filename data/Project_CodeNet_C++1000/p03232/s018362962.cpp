#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
const ll INF = 5e15;
const ll MOD = 1e9 + 7;

class Combination {
    public:
        ll N;
        ll MOD;
        ll *fact;

        /*
         * MOD must be a prime number.
         */
        Combination(ll N, ll MOD){
            this->N = N;
            this->MOD = MOD;
            fact = new ll[N + 1];
            fact[0] = 1;
            for(ll i = 1; i <= N; i++){
                fact[i] = fact[i - 1] * i % MOD;
            }
        }

        ll pow(ll a, ll b){
            return b ? (b & 1 ? a : 1) * pow(a * a % MOD, b / 2) % MOD : 1;
        }

        ll comb(ll n, ll k){
            return fact[n] * pow(fact[n - k] * fact[k] % MOD, MOD - 2) % MOD;
        }
};

int main(){
    Combination C(1e5 + 10, MOD);
    ll N;
    cin >> N;
    vector<ll> W(N);
    for(ll &w : W) cin >> w;
    ll ans = 0;
    vector<ll> cnt(N + 1);
    for(ll i = 2; i <= N; i++) cnt[i] = C.fact[i - 1] * C.fact[N - i] % MOD * C.comb(N, i) % MOD;
    vector<ll> sum(N + 1);
    for(ll i = 2; i <= N; i++) (sum[i] += sum[i - 1] + cnt[i]) %= MOD;
    for(ll i = 0; i < N; i++){
        (ans += W[i] * C.fact[N] % MOD) %= MOD;
        (ans += sum[i + 1] * W[i] % MOD) %= MOD;
        (ans += sum[N - i] * W[i] % MOD) %= MOD;
    }
    cout << ans << endl;
    return 0;
}
