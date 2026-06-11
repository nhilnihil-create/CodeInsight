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
    int N,C; cin >> N >> C;
    int D[C][C]; REP(i,C)REP(j,C) cin >> D[i][j];
    int c[N][N]; REP(i,N)REP(j,N) cin >> c[i][j];

    int n[C][3]; CLR(n);
    REP(i,N)REP(j,N){
        if((i+j)%3 == 0) n[c[i][j]-1][0]++;
        else if((i+j)%3 == 1) n[c[i][j]-1][1]++;
        else if((i+j)%3 == 2) n[c[i][j]-1][2]++;
    }
    int ans = INT_INF;
    REP(i,C)REP(j,C)REP(k,C){
        if(i==j || j==k || k==i) continue;
        int tmp = 0;
        REP(s,C){
            tmp += n[s][0]*D[s][i];
            tmp += n[s][1]*D[s][j];
            tmp += n[s][2]*D[s][k];
        }
        chmin(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}