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
#define EXIST(m,v) (m).find((v)) != (m).end()
#define LB(a,x) lower_bound((a).begin(), (a).end(), x) - (a).begin()
#define UB(a,x) upper_bound((a).begin(), (a).end(), x) - (a).begin()

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define RFOR(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define RREP(i,n) RFOR(i,n,0)

#define en "\n"

constexpr double EPS = 1e-9;
constexpr double PI  = 3.1415926535897932;
constexpr int INF = 2147483647;
constexpr long long LINF = 1LL<<60;
constexpr long long MOD = 1000000007; // 998244353;

#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

void compress(vector<ll> &v){
    ll N = v.size(), mn = LINF;
    vector<pair<ll,int>> a(N);
    for(int i=0; i<N; ++i){
        a[i].first = v[i];
        a[i].second = i;
        mn = min(mn, v[i]);
    }
    sort(a.begin(), a.end());
    
    int prev = mn-1, n = -1;
    for(int i=0; i<N; ++i){
        if(a[i].first == prev) v[a[i].second] = n;
        else{
            n++;
            prev = a[i].first;
            v[a[i].second] = n;
        }
    }
}

void Main(){
    ll N,A,B; cin >> N >> A >> B;

    if(!(A+B<=N+1 && A*B>=N)){
        cout << -1 << en;
        return;
    }

    auto f = [&](ll i, ll j){return i*A+j;};
    VL ans; REP(i,B) ans.push_back(f(B-1-i,0));
    N -= B;

    if(A>1){
        REP(i,N%(A-1)){
            REP(j,(N+A-2)/(A-1)) ans.push_back(f(B-1-j,i+1));
        }

        FOR(i,N%(A-1),A-1){
            REP(j,N/(A-1)) ans.push_back(f(B-1-j,i+1));
        }
    }

    N += B;
    compress(ans);
    REP(i,N) cout << ans[i]+1 << en;
    return;
}

int main(void){
    cin.tie(0);cout.tie(0);ios_base::sync_with_stdio(0);cout<<fixed<<setprecision(15);
    int t=1; //cin>>t;
    REP(_,t) Main();
    return 0;
}