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
    ll A,B,Q; cin >> A >> B >> Q;
    vector<ll> s(A+2), t(B+2);
    s[0] = -1e+18; s[A+1] = 1e+18; t[0] = -1e+18; t[B+1] = 1e+18;
    REP(i,A) cin >> s[i+1]; REP(i,B) cin >> t[i+1];

    REP(i,Q){
        ll x; cin >> x;
        ll si = lower_bound(ALL(s), x) - s.begin();
        ll ti = lower_bound(ALL(t), x) - t.begin();
        ll ans = LL_INF;
        chmin(ans, abs(x-s[si-1])+abs(s[si-1]-t[ti-1]));
        chmin(ans, abs(x-s[si-1])+abs(s[si-1]-t[ti]));
        chmin(ans, abs(x-s[si])+abs(s[si]-t[ti-1]));
        chmin(ans, abs(x-s[si])+abs(s[si]-t[ti]));
        chmin(ans, abs(x-t[ti-1])+abs(t[ti-1]-s[si-1]));
        chmin(ans, abs(x-t[ti-1])+abs(t[ti-1]-s[si]));
        chmin(ans, abs(x-t[ti])+abs(t[ti]-s[si-1]));
        chmin(ans, abs(x-t[ti])+abs(t[ti]-s[si]));
        cout << ans << endl;
    }
    return 0;
}