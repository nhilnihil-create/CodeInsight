#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

ll mod = 1e9+7;
#define NMAX 200010
ll fac[NMAX];
ll inv[NMAX];

ll mod_pow(ll a, ll n, ll mod){
    ll ret = 1;
    while(n > 0){
        if(n & 1) ret = (ret*(a % mod))%mod;
        a = ((a%mod)*(a%mod)) % mod;
        n = n >> 1;
    }
    return ret;
}

ll mod_inv(ll a, ll mod){
    return mod_pow(a, mod-2, mod);
}

void mae_nck(){
    fac[1] = 1;
    inv[1] = 1;
    for(ll i = 2; i < NMAX; i++){
        fac[i] = (fac[i-1] * i)%mod;
        inv[i] = (inv[i-1] * mod_inv(i, mod))%mod;
    }
}

ll mod_nck(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    if(k == 0 || k == n) return 1;
    ll ret = ((fac[n] * inv[k])%mod * inv[n-k])%mod;
    return ret;
}

int main(){
    string S;
    cin >> S;
    ll N = S.size();
    VL c(N+1, 0), q(N+1, 0), b(N+1, 0);
    for(ll i = N-1; i >= 0; i--){
        c[i] = c[i+1];
        q[i] = q[i+1];
        b[i] = b[i+1];
        if(S[i] == 'B') b[i]++;
        if(S[i] == 'C') c[i]++;
        if(S[i] == '?') q[i]++;
    }
    VL bc(N+1, 0), qq(N+1, 0), Bq(N+1, 0), qC(N+1, 0);
    for(ll i = N-1; i >= 0; i--){
        bc[i] = bc[i+1];
        qq[i] = qq[i+1];
        Bq[i] = Bq[i+1];
        qC[i] = qC[i+1];
        if(S[i] == 'B'){
            bc[i] += c[i+1];
            Bq[i] += q[i+1];
        }
        if(S[i] == '?'){
            qq[i] += q[i+1];
            qC[i] += c[i+1];
        }
        bc[i] %= mod;
        qq[i] %= mod;
        Bq[i] %= mod;
        qC[i] %= mod;
    }
    ll ans = 0;
    rep(i, 0, N){
        if(S[i] == 'A'){
            ans += bc[i+1] * mod_pow(3, q[0], mod);
            ans %= mod;
            ans += qq[i+1] * mod_pow(3, q[0]-2, mod);
            ans %= mod;
            ans += Bq[i+1] * mod_pow(3, q[0]-1, mod);
            ans %= mod;
            ans += qC[i+1] * mod_pow(3, q[0]-1, mod);
            ans %= mod;

            #ifdef DD
            cerr << i << " " << bc[i+1] * mod_pow(3, q[0], mod) << endl;
            cerr << i << " " << qq[i+1] * mod_pow(3, q[0]-2, mod) << endl;
            cerr << i << " " << Bq[i+1] * mod_pow(3, q[0]-1, mod) << endl;
            cerr << i << " " << qC[i+1] * mod_pow(3, q[0]-1, mod) << endl;
            #endif
        }

        if(S[i] == '?'){
            ans += bc[i+1] * mod_pow(3, q[0]-1, mod);
            ans %= mod;
            ans += qq[i+1] * mod_pow(3, q[0]-3, mod);
            ans %= mod;
            ans += Bq[i+1] * mod_pow(3, q[0]-2, mod);
            ans %= mod;
            ans += qC[i+1] * mod_pow(3, q[0]-2, mod);
            ans %= mod;

            #ifdef DD
            cerr << i << " " << bc[i+1] * mod_pow(3, q[0]-1, mod) << endl;
            cerr << i << " " << qq[i+1] * mod_pow(3, q[0]-3, mod) << endl;
            cerr << i << " " << Bq[i+1] * mod_pow(3, q[0]-2, mod) << endl;
            cerr << i << " " << qC[i+1] * mod_pow(3, q[0]-2, mod) << endl;
            #endif
        }
    }

//    rep(i, 0, N) cerr << qC[i] << endl;
    cout << ans << endl;
    return 0;
}