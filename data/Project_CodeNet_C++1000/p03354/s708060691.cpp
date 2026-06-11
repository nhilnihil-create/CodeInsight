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
//0.unionfind
template<class T>
struct UnionFind{
    vector<T> par;
    vector<T> ran;
    vector<T> siz;
    T tree_num;

    UnionFind(T n) : par(n),ran(n,0),siz(n,1),tree_num(n){
        rep(i,n){
            par[i] = i;
        }
    }
    T find(T x){
        if(x == par[x])return x;
        else return par[x] = find(par[x]);
    }
    void unite(T x,T y){
        x = find(x);
        y = find(y);
        if(x == y)return;
        tree_num--;
        if(ran[x] < ran[y]){
            siz[y] += siz[x];
            par[x] = y;
        }
        else{
            siz[x] += siz[y];
            par[y] = x;
            if(ran[x] == ran[y])ran[x]++;
        }
    }
    bool same(T x,T y){
        return find(x) == find(y);
    }
    T get_size(T x){
        return siz[find(x)];
    }
    T renketsu_seibun(){
        return tree_num;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //1.入力
    ll N,M;
    cin >> N >> M;
    vector<ll> vec(N);
    rep(i,N){
        cin >> vec[i];
        vec[i]--;
    }
    vector<ll> X(M),Y(M);
    rep(i,M){
        cin >> X[i] >> Y[i];
        X[i]--;Y[i]--;
    }
    //2.unionfindの構築
    UnionFind<ll> UF(N);
    rep(i,M){
        UF.unite(X[i],Y[i]);
    }
    //3.答えの決定
    ll ans = 0;
    rep(i,N){
        if(UF.same(vec[i],i))ans++;
    }
    //4.出力
    cout << ans << endl;
}