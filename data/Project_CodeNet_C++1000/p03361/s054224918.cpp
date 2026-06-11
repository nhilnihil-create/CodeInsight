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

void solve(){
	ll h,w;
	cin>>h>>w;
	vec<string> s(h);
	REP(i,h) cin>>s[i];

	ll dx[4]={0,0,1,-1};
	ll dy[4]={1,-1,0,0};

	REP(i,h){
		REP(j,w){
			if(s[i][j]=='.') continue;
			bool flag=false;
			REP(k,4){
				ll ni=i+dy[k];
				ll nj=j+dx[k];
				if(ni>=h || ni<0 || nj>=w || nj<0) continue;
				if(s[ni][nj]=='#') flag=true;

			}
			if(!flag) {
				cout<<"No"<<en;
				return;
			}
		}
	}
	cout<<"Yes"<<en;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    //ll t;cin>>t;REP(i,t) solve();

    return 0;
}