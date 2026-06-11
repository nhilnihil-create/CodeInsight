#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef long long ll;
typedef pair<ll, ll> P;

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

int main(void){
    ll N,K; cin >> N >> K;
    vector<P> v(N);
    REP(i,N){
        ll t,d; cin >> t >> d;
        t--;
        v[i].first = d; v[i].second = t;
    }
    SORT(v); REVERSE(v);
    vector<ll> m[N];
    ll sum_d=0, x=0;
    REP(i,K){
        if(m[v[i].second].empty()) x++;
        m[v[i].second].push_back(v[i].first);
        sum_d += v[i].first;
    }

    vector<ll> f(N+1,-LL_INF);
    f[x] = sum_d;

    priority_queue<ll,vector<ll>,greater<ll>> q;
    REP(i,N){
        if(m[i].size()>1){
            REP(j,m[i].size()-1) q.push(m[i][j+1]);
        }
    }

    int t = K;
    FOR(i,x+1,K+1){
        if(q.empty()) break;
        while(t<N && m[v[t].second].size()) t++;
        if(t == N) break;
        auto p = q.top(); q.pop();
        sum_d -= p;
        sum_d += v[t].first;
        m[v[t].second].push_back(v[t].first);
        f[i] = sum_d;
    }

    ll ans = 0;
    for(ll i=1; i<=K; i++) chmax(ans, f[i]+i*i);
    cout << ans << endl;
    return 0;
}