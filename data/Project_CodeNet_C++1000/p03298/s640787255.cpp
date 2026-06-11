#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef vector<vector<long long>> VVL;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

constexpr double EPS = 1e-9;
constexpr double PI  = 3.141592653589793238462643383279;
constexpr int INF = 2147483647;
constexpr long long LINF = 1LL<<60;
constexpr long long MOD = 1000000007; // 998244353;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){
    int N; cin >> N;
    string S; cin >> S;
    string A = S.substr(0,N), B = S.substr(N,N);
    REVERSE(B);

    vector<pair<string,string>> v;
    REP(i,1<<N){
        string s="", t="";
        REP(j,N) if((i>>j) & 1) s += A[j]; else t += A[j];
        v.emplace_back(s,t);
    }

    map<pair<string,string>, ll> m;
    REP(i,1<<N){
        string s="", t="";
        REP(j,N) if((i>>j) & 1) s += B[j]; else t += B[j];
        auto p = make_pair(s,t);
        if(m.find(p) != m.end()) m[p]++;
        else m[p] = 1;
    }

    ll ans = 0;
    for(auto p : v){
        string r = p.first, b = p.second;
        auto s = make_pair(b,r);
        if(m.find(s) != m.end()) ans += m[s];
    }
    cout << ans << en;
    return 0;
}