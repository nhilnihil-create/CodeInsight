// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x) cout << #x << " = " << (x) << endl;
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define SP << " " <<

typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
typedef vector<ll> vec;
typedef vector<P> pvec;
typedef vector<vector<ll>> vvec;
typedef vector<vector<P>> pvvec;
typedef priority_queue<ll> PQI;
typedef priority_queue<P> PQP;
typedef priority_queue<ll,vector<ll>,greater<ll>> PQIG;
typedef priority_queue<P,vector<P>,greater<P>> PQPG;

const vector<int> dx = {0, -1, 0, 1, 1, 1, -1, -1};
const vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
constexpr int MOD = (1000000007);
// const int MOD = (998244353);
// const int INF = (1 << 30); // 1073741824
const int INF = (1LL << 60); // 1152921504606846976
const double EPS = (1 >> 30);

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> inline T ceil(T a, T b) {return T((a + b - 1)/b);}
template< typename T1, typename T2 > istream &operator>>(istream &is, pair< T1, T2 > &p) { is >> p.first >> p.second; return is; }

int nmax=200000; // 2*(10^5)
vvec g(nmax);



signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    //---------------------------------------------
    
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    REP(i,m) cin >> a[i];
    sort(all(a));
    vec x={0,2,5,5,4,5,6,3,7,6};
    vec b;
    rep(i,m) b.pb(x[a[i]]);

    vec dp(n+10,-1);
    dp[0]=0LL;
    for(int i=1;i<=n;i++){
        rep(k,m){
            if(i-b[k]<0||dp[i-b[k]]==-1) continue;
            chmax(dp[i],dp[i-b[k]]+1);
        }
    }
    // rep(i,n+1) cout<<dp[i]<<" ";cout<<endl;

    pvec xx(m);
    rep(i,m) xx[i]=P(a[i],b[i]);
    sort(rall(xx));
    string ans="";
    for(int i=n;i>=0;i--){
        rep(j,m){
            if(i-xx[j].sc>=0&&dp[i]==dp[i-xx[j].sc]+1){
                ans+=to_string(xx[j].fs);
                i-=xx[j].sc;
                i++;
                // debug(dp[i]);
                // debug(dp[i-xx[j].sc]);
                break;
            }
        }
    }
    cout<<ans<<endl;
    
}