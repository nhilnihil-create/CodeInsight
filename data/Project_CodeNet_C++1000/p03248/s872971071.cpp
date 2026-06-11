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
constexpr long long MOD = 1000000007; // 998244353

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(void){
    string s; cin >> s;
    int N = s.size();
    if(!(s[0]=='1' && s[N-2]=='1' && s[N-1]=='0')){
        cout << -1 << endl;
        return 0;
    }
    REP(i,N-1){
        if(s[i]=='1' && s[N-2-i]=='0'){
            cout << -1 << endl;
            return 0;
        }
    }
    VI edge[N];
    queue<int> q; q.push(0);
    REP(i,N-1){
        if(s[i+1] == '0') q.push(i+1);
        else{
            while(!q.empty()){
                edge[i+1].push_back(q.front());
                q.pop();
            }
            q.push(i+1);
        }
    }
    edge[N-2].push_back(N-1);
    REP(i,N){
        REP(j,edge[i].size()) cout << i+1 << " " << edge[i][j]+1 << en;
    }
    return 0;
}