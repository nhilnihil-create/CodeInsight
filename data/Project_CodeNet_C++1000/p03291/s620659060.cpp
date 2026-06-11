#include <bits/stdc++.h>
using namespace std;
///////////////////////////////////////////
const long long int INF = 1LL<<60;
const long long int Mod = 1000000007;
using ll = long long int; using ci = const int;
using vi = vector<int>;  using Vi = vector<long long int>;
using P = pair<int, int>;  using PLL = pair<ll, ll>;
using matrix = vector<vector<ll>>;
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define rp(i,N) for(ll i = 0; i < (ll)N; i++)
#define repi(i,a,b) for(ll i = ll(a); i < ll(b); ++i)
template<class T>bool chmax(T &former, const T &b) { if (former<b) { former=b; return true; } return false; }
template<class T>bool chmin(T &former, const T &b) { if (b<former) { former=b; return true; } return false; }
template<class T>T sqar(T x){ return x*x; }//sqrt(x)は平方根;
#define Sort(v) std::sort(v.begin(), v.end(), std::greater<decltype(v[0])>()) //降順でVをソート
#define p_queue(v) priority_queue<v, vector<v>, greater<v> >
template<class T> inline void princ(T x){cout<<x<<" ";}; 
template<class T> inline void print(T x){cout<<x<<"\n";};
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
///////////////////////////////////////////////////////////////////////////////////
ll pow(ll x,ll y,ll mod){
    if(y==0) return 1;
    if(y&1) return x*pow(x,y-1,mod)%mod;
    ll p=pow(x,y/2,mod);
    return p*p%mod;
}
const ll MAX = 5000001;//10^7が限界
const ll MOD = Mod;
//const ll MOD = INT64_MAX;
ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

ll dp[100050][4];
void solve(){
    string s;
    cin >> s;
    int n=s.size();
    ll q=0;
    rp(i,n){
        if(s[i]=='?') q++;
    }
    COMinit();
    rp(i,n){
        if(s[i]=='A'){
            dp[i+1][1]=dp[i][1]+pow(3,q,Mod);
            dp[i+1][2]=dp[i][2];
            dp[i+1][3]=dp[i][3];
        }
        if(s[i]=='B'){
            dp[i+1][1]=dp[i][1];
            dp[i+1][2]=dp[i][1]+dp[i][2];
            dp[i+1][3]=dp[i][3];
        }
        if(s[i]=='C'){
            dp[i+1][1]=dp[i][1];
            dp[i+1][2]=dp[i][2];
            dp[i+1][3]=dp[i][2]+dp[i][3];
        }
        if(s[i]=='?'){
            dp[i+1][1]=dp[i][1]+pow(3,q-1,Mod);
            dp[i+1][2]=dp[i][1]*inv[3]+dp[i][2];
            dp[i+1][3]=dp[i][2]*inv[3]+dp[i][3];
        }
        dp[i+1][1]%=Mod;
        dp[i+1][2]%=Mod;
        dp[i+1][3]%=Mod;
    }
    print(dp[n][3]);
    return;
}
int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    std::cout<<std::fixed<<std::setprecision(30);
    solve();
    return 0;
}