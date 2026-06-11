#include<bits/stdc++.h>

using namespace std;

#define rep(i,m,n) for(int (i)=(int)(m);(i)<(int)(n);(i)++)
#define rep2(i,m,n) for(int (i)=(int)(n)-1;(i)>=(int)(m);(i)--)
#define REP(i,n) rep(i,0,n)
#define REP2(i,n) rep2(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
#define en '\n'
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;

typedef vector<ll> Array;
typedef vector<Array> Matrix;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

//constexpr long long MOD = (ll) 1e9+7;
constexpr long long MOD = 998244353;

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
	int to, cap, rev;
	Edge(int _to, int _cap, int _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph& G, int from, int to, int cap, bool revFlag, int revCap) {
	G[from].push_back(Edge(to, cap, G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, G[from].size() - 1));
}

template<class Abel> struct PotentialUnionFind {
 vector<int> par;
 vector<int> rank;
 vector<Abel> diff_weight;

 PotentialUnionFind(int n = 1, Abel SUM_UNITY = 0) {
  init(n, SUM_UNITY);
 }

 void init(int n = 1, Abel SUM_UNITY = 0) {
  par.resize(n); rank.resize(n); diff_weight.resize(n);
  for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
 }

 int root(int x) {
  if (par[x] == x) {
   return x;
  }
  else {
   int r = root(par[x]);
   diff_weight[x] += diff_weight[par[x]];
   return par[x] = r;
  }
 }

 Abel weight(int x) {
  root(x);
  return diff_weight[x];
 }

 bool issame(int x, int y) {
  return root(x) == root(y);
 }

 bool merge(int x, int y, Abel w) {
  w += weight(x); w -= weight(y);
  x = root(x); y = root(y);
  if (x == y) return false;
  if (rank[x] < rank[y]) swap(x, y), w = -w;
  if (rank[x] == rank[y]) ++rank[x];
  par[y] = x;
  diff_weight[y] = w;
  return true;
 }

 Abel diff(int x, int y) {
  return weight(y) - weight(x);
 }
};


void solve() {
    string s;
    cin>>s;
    ll n=s.size();
    ll con=0;
    ll ans=0;
    REP(i,n){
        if(s[i]=='A') con++;
        else if(i+1<n &&s.substr(i,2)=="BC"){ 
            ans+=con;
            i++;
        }else con=0;
    }
    cout<<ans<<en;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();
	//int t; cin >> t; REP(i, t) solve();

	return 0;
}
