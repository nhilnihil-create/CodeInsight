#include <bits/stdc++.h>
using namespace std;
/*{{{*/  //template
#define rep(i,n) for(int i=0;i<(int)(n);i++)
constexpr int INF = numeric_limits<int>::max()/2;
constexpr long long LINF = numeric_limits<long long>::max()/3;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<":"<<x<<endl
#define debug2(x,y) cerr<<#x<<","<<#y":"<<x<<","<<y<<endl
//struct fin{ fin(){ cin.tie(0); ios::sync_with_stdio(false); } } fin_;
struct Double{ double d; explicit Double(double x) : d(x){} };
ostream& operator<<(ostream& os,const Double x){ os << fixed << setprecision(20) << x.d; return os; }
template<typename T> ostream& operator<<(ostream& os,const vector<T>& vec){ os << "["; for(const auto& v : vec){ os << v << ","; } os << "]"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os,const pair<T,U>& p){ os << "(" << p.first << ","<< p.second <<")"; return os; }
template<typename T> ostream& operator<<(ostream& os,const set<T>& st){ os<<"{"; for(T v:st) os<<v<<","; os <<"}"; return os; }
template<typename T,typename U> inline void chmax(T &x,U y){ if(y>x) x = y; }
template<typename T,typename U> inline void chmin(T &x,U y){ if(y<x) x = y; }
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b); }
//constexpr double eps = 1e-14; 
constexpr double eps = 1e-10; 
constexpr ll mod = 1e9+7;
const int dx[]={1,0,-1,0} ,dy[] = {0,1,0,-1};
/*}}}*/

constexpr long long MAX_N = 100100;

ll fact[MAX_N];             // N!
ll fact_inv[MAX_N];         // N!の逆元

// O(log n)でx^n(modを法とする)
ll mod_pow(ll x,ll n,ll mod){
    ll res=1;
    while(n){
        if(n&1) res = (res*x)%mod;
        x = (x*x)%mod;
        n>>=1;
    }
    return res;
}

// O(log mod)で x^-1 を計算(法をmodとする)
ll invp(ll x,ll mod){
    return mod_pow(x,mod-2,mod);
}

// x / y をmodを法として行う
ll div_mod(ll x,ll y,ll mod){
    return x * invp(y,mod) % mod;
}

void init(){
    fact[0]=1;
    for(int i=1;i<MAX_N;i++) fact[i]=(fact[i-1]*i)%mod;
    for(int i=0;i<MAX_N;i++) fact_inv[i]=invp(fact[i],mod);
}

ll calc[MAX_N];
ll calcsum[MAX_N];

int main(){
    init();
    ll N; 
    cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    for(int i=0;i<=N;i++){
        if(i==0){
            calc[i] = 0;
        }else{
            calc[i] = div_mod(fact[N],i+1,mod);
        }
    }

    calcsum[0] = 0;
    for(int i=1;i<=N;i++){
        calcsum[i] = calcsum[i-1] + calc[i];
    }


    ll ans = 0;
    for(int i=0;i<N;i++){
        const ll L = i;
        const ll R = N - L - 1;

        ll calc = fact[N] + calcsum[L] + calcsum[R];
        calc %= mod;

        ans += calc * A[i] % mod;
        ans %= mod;
    }
    cout << ans << endl;
}
