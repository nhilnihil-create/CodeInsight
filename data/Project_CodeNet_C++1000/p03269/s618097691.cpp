#include <bits/stdc++.h>
using namespace std;

#define rep(i,m,n) for(int (i)=(int)(m);i<(int)(n);++i)
#define rep2(i,m,n) for(int (i)=(int)(n)-1;i>=(int)(m);--i)
#define REP(i,n) rep(i,0,n)
#define REP2(i,n) rep2(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define all(hoge) (hoge).begin(),(hoge).end()
#define en '\n'
using ll = long long;
using ull = unsigned long long;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
//constexpr long long MOD = (ll) 1e9 + 7;
constexpr long long MOD = 998244353LL;
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
using Edges = vector<Edge>;
using Graph = vector<Edges>;

void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

string ss[4] = {"dream","dreamer","erase","eraser"};
ll dp[101010];

bool dfs(const string& s,ll p){
	if(dp[p]!=-1) return dp[p];
	if(p==s.size()) return dp[p]=true;
	bool ret=false;
	REP(i,4){
		if(p+ss[i].size() > s.size()) continue;
		string s2=s.substr(p,ss[i].size());
		if(s2==ss[i]) if(dfs(s,p+ss[i].size())) ret=true; 
	}
	//cout<<p<<" "<<ret<<en;
	return dp[p]=ret;
}



void solve(){
	ll l;
	cin>>l;

	ll n=0;
	while((1<<n)<=l) n++;

	vec<tuple<ll,ll,ll>> es;
	REP(i,n-1){
		es.push_back(make_tuple(i+1,i+2,0));
		es.push_back(make_tuple(i+1,i+2,(1LL<<i)));
	}

	REP2(i,n-1){
		if(l>(1LL<<(i+1))){
			ll d=l-(1LL<<i);
			if(d<(1LL<<(n-1))) continue;
			es.push_back(make_tuple(i+1,n,d));
			l=d;
		}
	}
	cout<<n<<" "<<es.size()<<en;
	for(auto i:es){
		ll a,b,c;
		tie(a,b,c) = i;
		cout<<a<<" "<<b<<" "<<c<<en;
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    //ll t;cin>>t;REP(i,t) solve();

    return 0;
}