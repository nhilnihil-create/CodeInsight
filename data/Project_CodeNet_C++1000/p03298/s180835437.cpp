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

void solve(){
	ll n;
	cin>>n;
	string s;
	cin>>s;
	string t=s;
	reverse(all(t));

	ll ans=0;
	REP(bit,(1LL<<n)){
		Array red;
		Array blue;
		REP(i,n){
			if(bit&(1LL<<i)){
				red.push_back(i);
			}else{
				blue.push_back(i);
			}
		}
		Matrix dp(red.size()+1,Array(blue.size()+1,0));
		dp[0][0]=1;
		REP(i,red.size()+1){
			REP(j,blue.size()+1){
				if(i<red.size() && s[red[i]]==t[i+j]) dp[i+1][j]+=dp[i][j];
				if(j<blue.size() && s[blue[j]]==t[i+j]) dp[i][j+1]+=dp[i][j];
			}
		}
		ans+=dp[red.size()][blue.size()];
	}
	cout<<ans<<en;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}