#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str(); }
inline int readInt() { int x; scanf("%d", &x); return x; }

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;


//container util

//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)


struct Edge {
    int to, from;
    ll cost;
    Edge(int from, int to, ll cost): from(from), to(to), cost(cost) {}
};

typedef vector<vector<Edge>> AdjList;
AdjList graph;
int a[200010], b[200010];

int bits[29];
int main() {
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    //cout << fixed << setprecision(10);

    int N; cin >> N;

    int res = 0;
    REP(i, N) cin >> a[i];
    REP(i, N) cin >> b[i];
    
    for(int k = 29; k>=0; --k){
        int ub = 1<<(k+1), lb = 1<<k;
        
        for(int i=0; i<N; ++i) a[i]%=ub, b[i] %=ub;
        sort(b, b+N);
        
        ll num = 0;
        REP(i, N){
            int add = 0;
            if(lb-a[i]>=0){
                add += lower_bound(b, b+N, ub-a[i]) - lower_bound(b, b+N, lb-a[i]);
            }else{
                add += lower_bound(b, b+N, ub-a[i]) - b;
                add += lower_bound(b, b+N, ub) - lower_bound(b, b+N, ub+lb-a[i]);
            }
            num += add;
        }

        if(num & 1) res += lb;
    }
    cout << res << endl;
    
    return 0;

}