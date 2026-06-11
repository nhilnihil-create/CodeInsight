#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

const double EPS = 1e-9;
const double PI  = acos(-1.0);
const int INT_INF = 2147483647;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007; // 998244353

#define CLR(a) memset((a), 0, sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){
    int X,Y,Z,K; cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    REP(i,X) cin >> A[i]; REP(i,Y) cin >> B[i]; REP(i,Z) cin >> C[i];

    vector<ll> c;
    REP(i,X)REP(j,Y){
        c.push_back(A[i]+B[j]);
    }
    SORT(c); REVERSE(c); SORT(C); REVERSE(C);

    ll xl = 0, xr = 3e10, x = (xl+xr)/2;
    while(xr-xl>1){
        int tmp = 0;
        REP(i,Z){
            ll l = -1, r = c.size(), n = (l+r)/2;
            while(r-l>1){
                if(x <= C[i]+c[n]) l = n;
                else r = n;
                n = (l+r)/2;
            }
            tmp += r;
        }
        if(K <= tmp) xl = x;
        else xr = x;
        x = (xl+xr)/2;
    }

    vector<ll> ans;
    REP(i,Z){
        ll l = -1, r = c.size(), n = (l+r)/2;
        while(r-l>1){
            if(xl <= C[i]+c[n]) l = n;
            else r = n;
            n = (l+r)/2;
        }
        REP(j,r) ans.push_back(c[j]+C[i]);
    }

    SORT(ans); REVERSE(ans);
    REP(i,K) cout << ans[i] << en;
    return 0;
}