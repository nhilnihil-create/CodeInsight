#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> P;
typedef long long ll;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

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

string judge(int n){
    string s;
    cout << n << endl;
    cin >> s;
    return s;
}

int main(void){
    int N; cin >> N;
    string sl, sr;
    
    sl = judge(0);
    if(sl=="Vacant") return 0;

    int l = 0, r = N, n = (l+r)/2;
    if((n-l)%2==0) n++;

    while(r-l>2){
        sr = judge(n);
        if(sr=="Vacant") return 0;

        if(sl == sr) r = n;
        else{
            l = n;
            sl = sr;
        }
        n = (l+r)/2;
        if((n-l)%2==0) n++;
    }

    sl = judge(l+1);
    if(sl=="Vacant") return 0;
    sl = judge(l+2);
    if(sl=="Vacant") return 0;
    return 0;
}