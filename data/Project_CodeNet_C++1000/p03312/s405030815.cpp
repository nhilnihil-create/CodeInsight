#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

const double EPS = 1e-9;
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
    ll N; cin >> N;
    vector<ll> A(N); REP(i,N) cin >> A[i];
    vector<ll> S(N+1); S[0] = 0; REP(i,N) S[i+1] = S[i] + A[i];

    vector<ll> F(N-3,0), G(N-3,0);
    F[0] = 1;
    REP(i,N-4){
        int t = F[i];
        while(abs(S[i+3]-S[t]-S[t]) > abs(S[i+3]-S[t+1]-S[t+1])) t++;
        F[i+1] = t;
    }
    G[N-4] = N-1;
    REP(i,N-4){
        int t = G[N-4-i];
        while(abs(S[N]-S[t]-(S[t]-S[N-3-i])) > abs(S[N]-S[t-1]-(S[t-1]-S[N-3-i]))) t--;
        G[N-5-i] = t;
    }
    ll ans = LL_INF;
    REP(i,N-3){
        ll p = S[F[i]];
        ll q = S[i+2] - S[F[i]];
        ll r = S[G[i]] - S[i+2];
        ll s = S[N] - S[G[i]];
        chmin(ans, max(max(p,q),max(r,s))-min(min(p,q),min(r,s)));
    }
    cout << ans << endl;
    return 0;
}