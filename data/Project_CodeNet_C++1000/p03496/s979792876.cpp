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
typedef long long ll;
typedef pair<ll, ll> P;
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
    int N; cin >> N;
    vector<pair<ll,ll>> a(N); REP(i,N){ll x; cin >> x; a[i].first=x; a[i].second=i;}
    ll mx=a[0].first, mn=a[0].first; REP(i,N-1){chmax(mx, a[i+1].first); chmin(mn, a[i+1].first);}

    vector<P> ans;
    if(abs(mx) >= abs(mn)){
        priority_queue<pair<ll,ll>> q; REP(i,N) q.push(a[i]);
        REP(i,N){
            a[i].first += q.top().first; ans.push_back(pair<ll,ll>(q.top().second, a[i].second));
            if(i != 0 && a[i-1].first > a[i].first){
                a[i].first += q.top().first; ans.push_back(pair<ll,ll>(q.top().second, a[i].second));
            }
            q.push(a[i]);
        }
    }
    else{
        priority_queue<P, vector<P>, greater<P>> q; REP(i,N) q.push(a[i]);
        for(int i=N-1; i>=0; i--){
            a[i].first += q.top().first; ans.push_back(P(q.top().second, a[i].second));
            if(i != N-1 && a[i].first > a[i+1].first){
                a[i].first += q.top().first; ans.push_back(P(q.top().second, a[i].second));
            }
            q.push(a[i]);
        }
    }
    int m = ans.size();
    cout << m << endl;
    REP(i,m){
        cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
    }
    return 0;
}