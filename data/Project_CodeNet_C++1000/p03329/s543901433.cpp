#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
//#include <unistd.h>
//#include <stdio.h>
#define rep(i,x) for(ll i = 0;i<x;i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using namespace std;
using dou = double;
const ll inf = 2147483647;
const ll INF = 1LL << 60;
const ld pi = 3.14159265358;
const ll mod = 1000000007;
typedef pair<ll,ll> P;
using graph = vector<vector<ll>>;
template<class T> inline bool chmax(T& a, T b){if(a < b){a = b; return true;}return false;}
template<class T> inline bool chmin(T& a, T b){if(a > b){a = b; return true;}return false;}
ll gcd(ll a,ll b){
    if(a < b)swap(a,b);
    if(a % b == 0)return b;
    else return gcd(b,a%b);
}
//素数判定O(sqrt(N))
bool isp(ll n){
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

ll fac[510000], finv[510000], inv[510000];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < 510000; i++){
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = mod - inv[mod%i] * (mod / i) % mod;
        finv[i] = finv[i - 1] * inv[i] % mod;
    }
}

// 二項係数計算
ll nCk(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
}
//nのm乗をMODで割ったあまりO(logN)
ll modpow(ll n,ll m,ll MOD){
    ll res = 1;
    while(m){
        if(m & 1)res = (res * n) % MOD;
        m >>= 1;
        n *= n;
        n %= MOD;
    }
    return res;
}

//printf("%.10f\n", N);
/*  vector<ll> vec = {1,2,5,6,8,9,10};
    cout << binary_search(all(vec),5) << endl; -> true*/
/*
    vector<ll> vec = {1,2,5,6,8,9,10};
    auto n = upper_bound(all(vec),4);
    cout << *n << endl; -> 5*/

//    cout << fixed << setprecision(15);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    const ll NMAX = 100000;
    ll N;
    cin >> N;
    vector<ll> vec(NMAX + 5,INF);
    vec[0] = 0;
    vector<ll> six = {6,36,216,1296,7776,46656},nine = {9,81,729,6561,59049};//6,5
    for(ll i = 0;i <= NMAX;i++){
        rep(j,6){
            ll hx = six[j] + i;
            if(hx <= NMAX){
                chmin(vec[hx],vec[i] + 1);
            }
        }
        rep(j,5){
            ll hx = nine[j] + i;
            if(hx <= NMAX){
                chmin(vec[hx],vec[i] + 1);
            }
        }
        chmin(vec[i + 1],vec[i] + 1);
    }
    cout << vec[N] << endl;
    //rep(i,10)cout << vec[i] << "\n";
}