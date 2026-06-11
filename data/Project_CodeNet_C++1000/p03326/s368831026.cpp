#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
const ll INF = 1LL << 62;
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
//0.それぞれの状況での点数の最大値を計算する関数
ll sum(vector<ll> a,vector<ll> b,vector<ll> c,bool A,bool B,bool C,ll m){
    ll s = a.size();
    if(A)rep(i,s)a[i] = -a[i];
    if(B)rep(i,s)b[i] = -b[i];
    if(C)rep(i,s)c[i] = -c[i];
    vector<ll> vec(s);
    rep(i,s){
        vec[i] = a[i] + b[i] + c[i];
    }
    sort(all(vec),greater<ll>());
    ll res = 0;
    rep(i,m){
        res += vec[i];
    }
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //1.入力
    ll N,M;
    cin >> N >> M;
    vector<ll> bea(N),yum(N),pop(N);
    rep(i,N){
        cin >> bea[i] >> yum[i] >> pop[i];
    }
    //2.ansを更新していく
    ll ans = 0;
    rep(i,8){
        ans = max(ans,sum(bea,yum,pop,i >> 0 & 1,i >> 1 & 1,i >> 2 & 1,M));
        //cout << sum(bea,yum,pop,i >> 0 & 1,i >> 1 & 1,i >> 2 & 1,M) << "\n";
    }
    //3.出力
    cout << ans << endl;
}