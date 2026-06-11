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

ll n;
ll a[20];
ll dp[20][2];

ll dfs(ll i, ll j){
	
	if(dp[i][j]!=-1) return dp[i][j];
	if(i==n) return !j;
	if(j==1){
		ll ret=0;
		if(a[i]%2==0) ret += dfs(i+1, 0)+3*dfs(i+1,1);
		else ret += 2*dfs(i+1,0)+3*dfs(i+1, 1);
		return dp[i][j]=ret;

	}else{
		ll ret=0;
		if(a[i]%2==0) ret += 2 * dfs(i+1, 0);
		else ret += dfs(i+1, 0);
		return dp[i][j]=ret;
	}
}

void solve(){
	cin>>n;
	REP(i,n) cin>>a[i];
	memset(dp,-1,sizeof(dp));
	cout<<dfs(0,1)<<en;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
	//ll t;cin>>t;REP(i,t) solve();

    return 0;
}
