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

VI dp, p, q;

int rec(int n){
    if(dp[n] != -1) return dp[n];
    else if(n == p.size()-1) return dp[n] = 1;

    if(q[n+1] < q[n]) return dp[n] = 1;
    else return dp[n] = rec(n+1) + 1;

}
int main(void){
    int N; cin >> N;
    p.assign(N,0);
    q.assign(N,0);
    dp.assign(N,-1);
    REP(i,N){
        cin >> p[i];
        p[i]--;
        q[p[i]] = i;
    }

    REP(i,N){
        dp[i] = rec(i);
    }
    int ans = INT_INF;
    REP(i,N) chmin(ans, N-dp[i]);
    cout << ans << endl;
    return 0;
}