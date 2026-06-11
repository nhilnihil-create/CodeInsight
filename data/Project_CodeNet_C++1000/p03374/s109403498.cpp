#include <bits/stdc++.h>
using namespace std;

# define REP(i,n) for (int i=0;i<(n);++i)
# define rep(i,a,b) for(int i=a;i<(b);++i)
# define p(s) std::cout << s ;
# define pl(s)  std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;
# define yes(j) std::cout << (j ? "yes" : "no") << endl;
# define all(v) v.begin(),v.end()
# define showVector(v) REP(i,v.size()){p(v[i]);p(" ")} pl("")
template<class T> inline bool chmin(T &a, T b){ if(a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T &a, T b){ if(a < b) { a = b; return true;} return false;}
typedef long long int ll;
typedef pair<ll,ll> P_ii;
typedef pair<double,double> P_dd;

template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}

template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}

template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
  for(auto &e:t) fill_v(e,v);
}


const int MOD = 1000000007;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;

void addM(long long &a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

void mulM(long long &a, long long b) {
    a = ((a%MOD)*(b%MOD))%MOD ;
}

// テーブルを作る前処理
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
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
long long COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    ll N, C;
    cin >> N >> C;

    vector<ll> X(N + 2, 0), Y(N, 0);
    REP(i, N) cin >> X[i + 1] >> Y[i];
    X[N + 1] = C;

    vector<ll> h_X(N + 1, 0), t_X(N + 1, 0);
    REP(i, N) {
        h_X[i + 1] = h_X[i] + Y[i];
        t_X[N - i - 1] = t_X[N - i] + Y[N - i - 1];
    }

    ll ans = 0;
    
    vector<ll> ga(N + 1, 0);
    ll fa = 0;
    for(int i = 0; i <= N; i++) {
        chmax(fa, h_X[i] - X[i]);
        ga[i] = fa;
    }
    for(int i = N; i >= 0; i--) chmax(ans, t_X[i] - (C - X[i + 1]) * 2 + ga[i]);

    vector<ll> gb(N + 1, 0);
    ll fb = 0;
    for(int i = N; i >= 0; i--) {
        chmax(fb, t_X[i] - (C - X[i + 1]));
        gb[i] = fb;
    }
    for(int i = 0; i <= N; i++) chmax(ans, h_X[i] - X[i] * 2 + gb[i]);

    pl(ans)

    return 0;
}
