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
	ll n;
	cin>>n;
	vec<ll> a(n);
	REP(i,n) cin>>a[i];

	map<ll,ll> mp1,mp2;
	REP(i,n/2){
		mp1[a[2*i]]++;
		mp2[a[2*i+1]]++;
	}

	vec<P> v1,v2;
	for(auto i:mp1){
		v1.push_back({-i.second,i.first});
	}
	for(auto i:mp2){
		v2.push_back({-i.second,i.first});
	}
	v1.push_back({0,-1});
	v2.push_back({0,-1});

	sort(all(v1));
	sort(all(v2));

	if(v1[0].second==v2[0].second){
		cout<<min(n+v1[0].first+v2[1].first,n+v1[1].first+v2[0].first)<<en;
	}else{
		cout<<n+v1[0].first+v2[0].first<<en;
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