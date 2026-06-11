#include <bits/stdc++.h>
using namespace std;

#define rep(i,m,n) for(int (i)=(int)(m);i<(int)(n);i++)
#define rep2(i,m,n) for(int (i)=(int)(n)-1;i>=(int)(m);i--)
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
constexpr long long MOD = (ll) 1e9 + 7;
//constexpr long long MOD = 998244353LL;
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
    string s;
    cin>>n>>s;

    vvec<ll> dp(n,vec<ll>(n,0));
    REP(i,n) dp[0][i]=1;
    REP(i,n-1) {
        vec<ll> sum(n+1,0);
        REP(j,n) (sum[j+1] = sum[j]+dp[i][j])%=MOD;
        REP(j,n-i-1){
            if(s[i]=='<'){
                //前よりも大きい値を選ぶ→大きい値がj+1個以上あるやつからしかえらべない
                dp[i+1][j] = (MOD + sum[n-i] - sum[j+1])%MOD;
            }else{
                //前よりも小さい数を選ぶ→前よりも大きい数が増えることはない
                dp[i+1][j] = (MOD + sum[j+1] - sum[0])%MOD;
            }
        }
    }
    cout<<dp[n-1][0]<<en;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    //ll t;cin>>t;REP(i,t) solve();

    return 0;
}