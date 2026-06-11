#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#define rep(i,x) for(ll i = 0;i<x;i++)
#define all(a) (a).begin(),(a).end()
#define vecin(a) rep(i,a.size())cin >> a[i]
#define vecout(a) rep(i,a.size()){cout << a[i];cout << (i == a.size() - 1 ? "\n":" ");}
#define mp make_pair
using ll = long long;
using ld = long double;
using namespace std;
using dou = double;
const ll inf = 2147483647;
const ll INF = 1LL << 60;
const dou pi = 3.14159265358;
const ll mod = 1000000007LL;
typedef pair<ll,ll> P;
using graph = vector<vector<ll>>;
template<class T> inline bool chmax(T& a, T b){if(a < b){a = b; return true;}return false;}
template<class T> inline bool chmin(T& a, T b){if(a > b){a = b; return true;}return false;}
template<class T> inline bool change(T a,T b){if(a > b){swap(a,b);return true;}return false;}
ll gcd(ll a,ll b){
    if(a < b)swap(a,b);
    if(a % b == 0)return b;
    else return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a / gcd(a,b) * b;
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
const ll cmax = 1000000;
ll fac[cmax], finv[cmax], inv[cmax];

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
    ll N;
    cin >> N;
    map<ll,ll> ma;
    if(N <= 9){
        cout << "0\n";
        return 0;
    }
    for(ll i = 2;i <= N;i++){
        ll n = i,m = i;
        for(ll j = 2;j * j <= n;j++){
            while(m % j == 0){
                m /= j;
                ma[j]++;
            }
        }
        if(m != 1)ma[m]++;
    }
    ll ans = 0;
    if(ma[2] >= 74)ans++;//1 75
    vector<ll> vec;
    for(auto x : ma){
        vec.push_back(x.second);
    }
    ll s = vec.size();
    rep(i,s){
        if(vec[i] >= 24){
            rep(j,s){
                if(i == j)continue;
                if(vec[j] >= 2){
                    ans++;
                }
            }
        }
    }
    rep(i,s){
        if(vec[i] >= 14){
            rep(j,s){
                if(i == j)continue;
                if(vec[j] >= 4)ans++;
            }
        }
    }
    rep(i,s){
        if(vec[i] >= 4){
            for(ll j = i + 1;j < s;j++){
                if(vec[j] >= 4){
                    rep(k,s){
                        if(j == k || k == i)continue;
                        if(vec[k] >= 2)ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
//75 25 15
//1  3  5 
//3 * 5 * 5