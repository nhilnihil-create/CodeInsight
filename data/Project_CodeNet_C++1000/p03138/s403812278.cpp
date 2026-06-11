#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

const double EPS = 1e-10;
const double PI  = acos(-1.0);
const int INT_INF = 2147483647;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007;

#define CLR(a) memset((a), 0 ,sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){
    ll N,K; cin >> N >> K;
    vector<ll> A(N); REP(i,N) cin >> A[i];
    if(K == 0){
        ll sum = 0;
        REP(i,N) sum += A[i];
        cout << sum << endl;
        return 0;
    }
    ll digit = 0;
    REP(i,60) if(K>>i) digit++; else break;
    ll c = 0;
    REP(i,N) c += A[i]>>digit;
    c <<= digit;

    ll n[digit+1][2]; CLR(n);
    REP(i,digit){
        REP(j,N){
            if(A[j]>>i & 1) n[digit-i][1]++;
            else n[digit-i][0]++;
        }
    }

    ll dp[digit+1][2]; CLR(dp);
    dp[1][0] = n[1][0];
    dp[1][1] = n[1][1];
    FOR(i,1,digit){
        dp[i+1][0] = dp[i][0]*2 + n[i+1][!(K>>(digit-1-i)&1)];
        dp[i+1][1] = dp[i][1]*2 + max(n[i+1][0], n[i+1][1]);
        if(K>>(digit-1-i)&1) dp[i+1][1] = max(dp[i+1][1], dp[i][0]*2 + n[i+1][1]);
    }

    ll ans = c + max(dp[digit][0], dp[digit][1]);
    cout << ans << endl;
    return 0;
}