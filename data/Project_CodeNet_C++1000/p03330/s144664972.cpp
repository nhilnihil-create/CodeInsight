#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

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
    int N,C; cin >> N >> C;
    int D[C][C]; REP(i,C)REP(j,C) cin >> D[i][j];
    int c[N][N];
    REP(i,N)REP(j,N){
        int cc; cin >> cc; cc--;
        c[i][j] = cc;
    }

    int num[3][C];
    REP(i,3)REP(j,C) num[i][j] = 0;
    REP(i,N)REP(j,N) num[(i+j)%3][c[i][j]]++;

    int ans = INT_INF;
    REP(i,C)REP(j,C)REP(k,C){
        if(i==j || j==k || k==i) continue;
        int tmp = 0;
        REP(t,C) tmp += num[0][t]*D[t][i];
        REP(t,C) tmp += num[1][t]*D[t][j];
        REP(t,C) tmp += num[2][t]*D[t][k];
        chmin(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}