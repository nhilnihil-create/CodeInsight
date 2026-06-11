#include <bits/stdc++.h>
#include <iomanip>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
/*----------------------------------ここからマクロ----------------------------------*/
#define all(a) (a).begin(),(a).end()
#define vecin(a) rep(i,a.size())cin >> a[i]
#define vecout(a) rep(i,a.size()){cout << a[i];cout << (i == a.size() - 1 ? "\n":" ");}
#define overload4(_1,_2,_3,_4,name,...) name
/*#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)*/
#define rep1(n) for(int i=0;i<n;++i)
#define rep2(i,n) for(int i=0;i<n;++i)
#define rep3(i,a,b) for(int i=a;i<b;++i)
#define rep4(i,a,b,c) for(int i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define mp make_pair
#define debug(x) cerr << #x << ": " << x << "\n"
#define myset ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define doset(x) cout << fixed << setprecision(x)
using ll = long long;
using ld = long double;
using namespace std;
using dou = double;
const int inf = 1 << 29;
const ll INF = 1LL << 60;
const dou pi = 3.14159265358;
const ll mod = 1000000007LL;
//const ll mod = 998244353LL;
typedef pair<ll,ll> P;
using graph = vector<vector<ll>>;
template<class T, class U> inline bool chmin(T& a, const U& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T, class U> inline bool chmax(T& a, const U& b){ if(a < b){ a = b; return 1; } return 0; }
template<class T, class U> inline bool change(T& a,U& b){if(a > b){swap(a,b);return 1;}return 0;}
//0の場合のアレンジに注意
template<class T>
T gcd(T a,T b){
    if(a == 0)return b;
    else if(b == 0)return a;
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

template<class T = ll>
T in(){T x;cin >> x;return x;}

/*----------------------------------マクロここまで----------------------------------*/

typedef pair<char,ll> pii;
int main(){
    myset;
    ll N,M;
    cin >> N >> M;
    string S;//１連続
    cin >> S;
    vector<pii> vec;
    vec.push_back(pii(S[0],0));
    ll cnt = 0;
    rep(i,N){
        if(S[i] != vec[cnt].first){
            cnt++;
            vec.push_back(pii(S[i],1));
        }
        else{
            vec[cnt].second++;
        }
    }
    if(vec.size() == 1){
        cout << vec[0].second << "\n";
        return 0;
    }
    cnt++;
    ll Z = 0;
    vector<ll> wa(cnt + 1);
    rep(i,cnt){
        if(vec[i].first == '0')Z++;
        wa[i + 1] = vec[i].second;
    }
    rep(i,cnt){
        wa[i + 1] += wa[i];
    }//2 * M + 1こ連続
    if(M >= Z){
        cout << N << "\n";
        return 0;
    }
    ll ans = 0;
    bool one = (S[0] == '1' ? 1:0);
    for(ll i = 0;i < Z - M + 1;i++){
        ll le = (i == 0 ? 0:i * 2 - !one),ri;
        if(i == 0){
            ri = 2 * M + one;
        }
        else if(i == Z - M){
            ri = cnt;
        }
        else{
            ri = le + 2 * M + 1;
        }
        chmax(ans,wa[ri] - wa[le]);
    }
    cout << ans << "\n";
}