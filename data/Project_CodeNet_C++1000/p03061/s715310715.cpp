#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#define all(a) (a).begin(),(a).end()
#define vecin(a) rep(i,a.size())cin >> a[i]
#define vecout(a) rep(i,a.size()){cout << a[i];cout << (i == a.size() - 1 ? "\n":" ");}
#define rep(i,x) for(ll i = 0;i<x;i++)
#define REP(i,x) for(ll i = 1;i<=x;i++)
#define mp make_pair
using ll = long long;
using ld = long double;
using namespace std;
using dou = double;
const ll inf = 2147483647;
const ll INF = inf;
const dou pi = 3.14159265358;
const ll mod = 1000000007LL;
//const ll mod = 998244353LL;
typedef pair<ll,ll> P;
using graph = vector<vector<ll>>;
template<class T, class U> inline bool chmin(T& a, const U& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T, class U> inline bool chmax(T& a, const U& b){ if(a < b){ a = b; return 1; } return 0; }
template<class T, class U> inline bool change(T& a,U& b){if(a > b){swap(a,b);return 1;}return 0;}
template<class T>
T gcd(T a,T b){
    if(a < b)swap(a,b);
    if(a % b == 0)return b;
    else return gcd(b,a%b);
}
template<class T>
T lcm(T a,T b){
    return a / gcd(a,b) * b;
}

//素数判定O(sqrt(N))
template<class T>
inline bool isp(T n){
    bool res = true;
    if(n == 1)return false;
    else{
        for(ll i = 2;i * i <= n;i++){
            if(n % i == 0){
                res = false;
                break;
            }
        }
        return res;
    }
}
const ll cmax = 1000000;
vector<ll> fac(cmax),finv(cmax),inv(cmax);

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < cmax; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

// 二項係数計算
ll nCk(ll n, ll k){
    if(fac[0] == 0)COMinit();
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
//nのm乗をMODで割ったあまりO(logm)
ll modpow(ll n,ll m,ll MOD){
    if(m == 0)return 1;
    if(m < 0)return -1;
    ll res = 1;
    while(m){
        if(m & 1)res = (res * n) % MOD;
        m >>= 1;
        n *= n;
        n %= MOD;
    }
    return res;
}
ll mypow(ll n,ll m){
    if(m == 0)return 1;
    if(m < 0)return -1;
    ll res = 1;
    while(m){
        if(m & 1)res = (res * n);
        m >>= 1;
        n *= n;
    }
    return res;
}

struct segtree{
    ll n;
    vector<ll> dat;
    segtree(ll _n):n(),dat(_n * 4,-1){
        ll x = 1;
        while(x < _n){
            x *= 2;
        }
        n = x;
    }

    void update(ll a,ll m){
        a += n - 1;
        dat[a] = m;
        while(a > 0){
            a = (a - 1) / 2;
            if(dat[a * 2 + 1] == -1 || dat[a* 2 + 2] == -1)break;
            dat[a] = gcd(dat[a * 2 + 1],dat[a * 2 + 2]);
        }
    }

    ll query_sub(ll a,ll b,ll k,ll l,ll r){
        if(l >= b || r <= a)return -1;
        else if(a <= l && r <= b){
            return dat[k];
        }
        else{
            ll le = query_sub(a,b,k * 2 + 1,l,(l + r) / 2);
            ll ri = query_sub(a,b,k * 2 + 2,(l + r) / 2,r);
            if(le == -1 && ri == -1)return -1;
            else if(le == -1 && ri != -1)return ri;
            else if(le != -1 && ri == -1)return le;
            else return gcd(le,ri);
        }
    }
    ll query(ll a,ll b){
        return query_sub(a,b,0,0,n);
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    ll N;
    cin >> N;
    vector<ll> vec(N);
    vecin(vec);
    segtree ST(N);
    rep(i,N){
        ST.update(i,vec[i]);
    }
    ll ans = 0;
    rep(i,N){
        if(i == 0){
            chmax(ans,ST.query(1,N));
        }
        else if(i == N - 1){
            chmax(ans,ST.query(0,N - 1));
        }
        else{
            ll le = ST.query(0,i);
            ll ri = ST.query(i + 1,N);
            chmax(ans,gcd(le,ri));
        }
    }
    cout << ans << endl;
}