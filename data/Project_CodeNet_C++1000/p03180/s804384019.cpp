#include <bits/stdc++.h>

using namespace std;

#define rep(i,m,n) for(int (i)=(int)(m);i<(int)(n);i++)
#define rep2(i,m,n) for(int (i)=(int)(n)-1;i>=(int)(m);i--)
#define REP(i,n) rep(i,0,n)
#define REP2(i,n) rep2(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
#define en '\n'
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll) 1e9 + 7;
typedef vector<ll> Array;
typedef vector<Array> Matrix;
constexpr int loose = 0;
constexpr int tight = 1;


template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

struct Edge {
	ll to, cap, rev;
	Edge(ll _to, ll _cap, ll _rev) {
	to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

ll dp1[101010];
ll dp2[101010];

ll rec(ll s){
	if(dp2[s]!=-1) return dp2[s];
	ll ret = dp1[s];
	for(ll i=(s-1)&s; i>0; i=(i-1)&s){
		chmax(ret, rec(i)+rec(i^s));
	}
	return dp2[s]=ret;
}

void solve(){
	ll n;
	cin>>n;
	Matrix a(n,Array(n));
	REP(i,n) REP(j,n) cin>>a[i][j];

	REP(bit,(1LL<<n)){
		Array as;
		REP(i,n) if(bit&(1LL<<i)) as.push_back(i);
		REP(i,as.size()) rep(j,i+1,as.size()) dp1[bit]+=a[as[i]][as[j]];
	}

	REP(i,(1LL<<n)) dp2[i]=-1;

	cout<<rec((1LL<<n)-1)<<en;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}