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

int dif(int d1, int d2){
    return min(abs(d1-d2), abs(24-abs(d1-d2)));
}

int mind(int pos, VI& v){
    int r = pos, l = pos;
    int dr = 0, dl = 0;
    while(r<24 && v[r]==0){r++; dr++;}
    if(r == 24){
        r = 0;
        while(v[r]==0){r++; dr++;}
    }
    while(l>-1 && v[l]==0){l--; dl++;}
    if(l == -1){
        l = 23;
        while(v[l]==0){l--; dl++;}
    }
    return min(dr,dl);
}

int main(void){
    int N; cin >> N;
    VI D(N+1,0); REP(i,N) cin >> D[i];
    SORT(D); REVERSE(D);
    int l = 0, r = 13, n = (l+r)/2;
    while(r-l>1){
        VI loc(24,0); loc[12] = 1;
        bool flag = true;
        REP(i,N){
            if(mind(12-D[i], loc) >= n) loc[12-D[i]] = 1;
            else if(mind((12+D[i])%24, loc) >= n) loc[(12+D[i])%24] = 1;
            else{
                flag = false;
                break;
            }
        }
        if(flag) l = n;
        else r = n;
        n = (l+r)/2;
    }
    int ans = l;
    cout << ans << en;
    return 0;
}