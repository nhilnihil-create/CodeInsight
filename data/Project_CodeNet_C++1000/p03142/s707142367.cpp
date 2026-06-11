#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_back
#define ub upper_bound
#define lb upper_bound
#define mp make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SORT(c) sort((c).begin(),(c).end())
#define ve vector
#define vi vector<int>
#define vp vector<pair<int,int>>
#define vvi vector<vector<int>>
 
typedef long long ll;
const ll INF = LLONG_MAX - 100;
const ll mod = 1e9 + 7;
const int MAX_N = 2e5 + 5;
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
vector<ll> prime;
 
int fac[MAX_N], inv[MAX_N];
 
template <class T = ll> T in() {T x; cin >> x; return (x);}
void DEBUG(vector<int> a) {for(int i=0;i<a.size();i++)cout<<a[i]<<" ";cout<<endl;}
ll GCD(ll a, ll b) {ll c; while (b != 0) {c = a % b; a = b; b = c;}return a;}
ll LCM(ll a, ll b) {return a * b / GCD(a, b);}
ll POW(ll a, ll b, bool usemod = true) {ll c = 1LL; while (b > 0) {if (b & 1LL) {if(!usemod)c*=a;else c = a * c%mod;}if (!usemod) a*=a;else a = a * a%mod; b >>= 1LL;}return c;}
void _nCr() {fac[0] = 1LL; for (int i = 1LL; i < MAX_N; i++) {fac[i] = fac[i - 1LL] * i%mod;}for (int i = 0; i < MAX_N; i++) {inv[i] = POW(fac[i], mod - 2);}}
ll nCr(ll n, ll r) {return (fac[n] * inv[r] % mod)*inv[n - r] % mod;}
void PRI(ll n) {bool a[n + 1LL]; for (int i = 0; i < n + 1LL; i++) {a[i] = 1LL;}for (int i = 2; i < n + 1LL; i++) {if (a[i]) {prime.pb(i); ll b = i; while (b <= n) {a[b] = 0; b += i;}}}}
template <typename T> T chmin(T& a, T b) {if(a>b)a=b;return a;}
template <typename T> T chmax(T& a, T b) {if(a<b)a=b;return b;}

class UnionFind {
private:
	vector<int> par;
public:
	vector<set<int>> X;
	vector<set<int>> Y;
	UnionFind(int N) {par = vector<int>(N, -1);}
	int find(int x);
	ll size(int x);
	void unite(int x, int y);
	bool same(int x, int y);
};

int UnionFind::find(int x) {
	if (par[x] < 0) return x;
	else return par[x] = find(par[x]);
}
 
ll UnionFind::size(int x) {
	return -par[find(x)];
}
 
void UnionFind::unite(int x, int y) {
	x = find(x);
	y = find(y);
 	if (x == y) return;
	//大きい方に小さい方をくっ付ける
	if (size(x) < size(y)) swap(x, y);
	par[x] += par[y];
	par[y] = x;
}
 
bool UnionFind::same(int x, int y) {
	x = find(x);
	y = find(y);
	return x == y;
}

int v,e;
const int MAX = 100010;
vector<int> g[MAX];
bool used[MAX];
vector<int> ans;
int anc[MAX];

void dfs(int u) {
	if (used[u]) return;
	used[u] = true;
	for (auto & i : g[u]) {
		dfs(i);
	}
	ans.push_back(u);
}

void tsort() {
	REP (i,MAX) anc[i] = 0;
	REP (i,v) dfs(i);
	reverse(ALL(ans));
}

bool solve() {
	int n,m;cin >> n >> m;
	v = n; e = n + m -1;
	REP (i,n+m-1) {
		int s,t;cin >> s >> t;
		g[--s].push_back(--t);
	}
	tsort();
	REP (i,n) {
		for (auto &a : g[ans[i]]) {
			anc[a] = ans[i]+1;
		}
	}
	REP (i,n) {
		cout << anc[i] << endl;
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	solve();
}