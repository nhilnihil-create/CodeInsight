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
const long long INT_INF = 998244353;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007;

#define CLR(a) memset((a), 0 ,sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){
    int K = 50;
    int A,B; cin >> A >> B;
    char s[2*K][2*K];
    REP(i,K)REP(j,2*K){s[i][j] = '#'; s[i+K][j] = '.';}
    int I=(A-1)/50, J=(A-1)%50; REP(i,I)REP(j,K) s[2*i][2*j] = '.';
    REP(j,J) s[2*I][2*j] = '.';
    I=(B-1)/50, J=(B-1)%50; REP(i,I)REP(j,K) s[2*i+K+1][2*j] = '#';
    REP(j,J) s[2*I+K+1][2*j] = '#';

    cout << 2*K << " " << 2*K << endl;
    REP(i,2*K){
        REP(j,2*K) cout << s[i][j];
        cout << endl;
    }
    return 0;
}