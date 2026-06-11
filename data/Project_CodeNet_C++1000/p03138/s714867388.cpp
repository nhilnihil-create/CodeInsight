#include <bits/stdc++.h>
using namespace std;
/*{{{*/  //template
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
constexpr int INF = numeric_limits<int>::max()/2;
constexpr long long LINF = numeric_limits<long long>::max()/3;
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
template<typename T,typename U> ostream& operator<<(ostream& os, const map<T,U>& mp){ os << "{"; for(auto& p : mp){ os << p << ","; } os << "}"; return os; }
template<typename T,typename U> ostream& operator<<(ostream& os,const pair<T,U>& p){ os << "(" << p.first << ","<< p.second <<")"; return os; }
template<typename T> ostream& operator<<(ostream& os,const set<T>& st){ os<<"{"; for(T v:st) os<<v<<","; os <<"}"; return os; }
template<typename T,typename U> inline void chmax(T &x,U y){ if(y>x) x = y; }
template<typename T,typename U> inline void chmin(T &x,U y){ if(y<x) x = y; }
using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int,int>;
using vi = std::vector<int>;
typedef vector<vi> vvi;
ll gcd(ll a,ll b){ if(b==0) return a; else return gcd(b,a%b); }
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
//constexpr double eps = 1e-14; 
constexpr double eps = 1e-10; 
constexpr ll mod = 1e9+7;
const int dx[]={1,0,-1,0} ,dy[] = {0,1,0,-1};
/*}}}*/

#define BITS 50

int main(){
    ll N,K; cin >> N >> K;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    //cout << bitset<BITS>(A[0]) << endl;

    vi cnt(BITS);
    rep(i,N){
        rep(j,BITS){
            if(A[i] & (1LL << ll(j))){
                cnt[j]++;
            }
        }
    }
    //cout << cnt << endl;

    ll dp[BITS+1][2];
    rep(i,BITS+1) rep(j,2) dp[i][j]=-1;
    dp[0][0] = 0;

    for(int i=0;i<BITS;i++){
        ll bit = BITS - 1 - i;
        for(int j=0;j<2;j++){
            if(dp[i][j] == -1) continue;
            int x = (K & (1LL << bit)) > 0;
            ll lim = (j) ? 1 : x;
            ll y; // want to use
            if(cnt[bit] <= N/2){
                y = 1;
            }else{
                y = 0;
            }
            //printf("bit = %lld, flag = %d, lim = %d, try = %lld\n",bit,j,x,y);
            if(y <= lim){
                dp[i+1][j || (y < x)] = dp[i][j] | (y << bit);
            }else{
                dp[i+1][j] = dp[i][j];
            }
        }
    }
    ll X = max(dp[BITS][0], dp[BITS][1]);
    /* debug(X); */
    /* debug(bitset<BITS>(X)); */

    ll ans = 0;
    rep(i,N){
        ans += X ^ A[i];
    }
    cout << ans << endl;


    /* for(int i=0;i<=BITS;i++){ */
    /*     cout << i << " " << bitset<BITS>(dp[i][0]) << " " << bitset<BITS>(dp[i][1]) << endl; */
    /* } */
}
