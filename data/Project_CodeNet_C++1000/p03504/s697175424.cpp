//include
//------------------------------------------
#include <bits/stdc++.h>
using namespace std;
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const long long INF = 1000000007;
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
// chmax chmin
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){
    int N,C; cin >> N >> C;
    vector<vector<P>> v(C);
    int f = 0;
    REP(i,N){
        int s,t,c; cin >> s >> t >> c;
        v[c-1].push_back(P(s-1,t-1));
        chmax(f, t-1);
    }
    REP(i,C) SORT(v[i]);
    vector<vector<P>> newv(C);
    REP(i,C){
        if(v[i].size()) newv[i].push_back(P(v[i][0].first, v[i][0].second));
        FOR(j,1,v[i].size()){
            if(v[i][j].first == newv[i].back().second) newv[i].back().second = v[i][j].second;
            else newv[i].push_back(P(v[i][j].first, v[i][j].second));
        }
    }
    swap(v,newv);
    int n[f]; REP(i,f) n[i] = 0;
    REP(i,C){
        for(P p : v[i]){
            FOR(j, p.first, p.second+1){
                n[j]++;
            }
        }
    }
    int ans = 0;
    REP(i,f) chmax(ans, n[i]);
    cout << ans << endl;
    return 0;
}