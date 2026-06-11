#include <bits/stdc++.h>
using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<ll, ll> P;
typedef tuple<int,int,int> tpl;

#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define REVERSE(c) reverse((c).begin(),(c).end())

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

const double EPS = 1e-9;
const double PI  = acos(-1.0);
const int INT_INF = 2147483647;
const long long LL_INF = 1LL<<60;
const long long MOD = 1000000007;

#define CLR(a) memset((a), 0 ,sizeof(a))

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

bool comp(P a, P b){
    return a.second < b.second;
}

int main(void){
    ll N,K; cin >> N >> K;
    vector<P> v(N); REP(i,N){cin >> v[i].first >> v[i].second; v[i].first--;}
    sort(ALL(v), comp); REVERSE(v);
    vector<vector<ll>> n(N);
    ll sum = 0, x = 0;
    REP(i,K){
        sum += v[i].second;
        if(n[v[i].first].size() == 0) x++;
        n[v[i].first].push_back(v[i].second);
    }
    vector<ll> f(N+1,-LL_INF);
    f[x] = sum;

    priority_queue<P,vector<P>,greater<P>> q;
    REP(i,N){
        if(n[i].size() > 1) REP(j,n[i].size()-1) q.push(P(n[i][j+1], i));
    }

    FOR(i,K,N){
        ll t = v[i].first, d = v[i].second;
        if(n[t].size()) continue;
        if(q.empty()) break;
        P p = q.top(); q.pop();
        sum -= p.first;
        sum += d;
        x++;
        f[x] = sum;
        n[t].push_back(d);
    }

    ll ans = 0;
    REP(i,N) chmax(ans, f[i+1]+((ll)i+1)*((ll)i+1));
    cout << ans << endl;
    return 0;
}