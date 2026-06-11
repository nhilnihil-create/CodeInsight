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

bool check(string &s){
    bool flag = true;
    REP(i,s.size()/2){
        if(s[i] != s[s.size()-1-i]){
            flag = false;
            break;
        }
    }
    return !flag;
}

int main(void){
    string s; cin >> s;
    string rmv = "";
    REP(i,s.size()) if(s[i]!='x') rmv += s[i];
    if(check(rmv)){
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    
    int l = 0, r = s.size()-1;
    while(l < r){
        if(s[l]!=s[r]){
            if(s[l]=='x') l++;
            else r--;
            ans++;
        }
        else{
            l++;
            r--;
        }
    }
    cout << ans << endl;
    return 0;
}