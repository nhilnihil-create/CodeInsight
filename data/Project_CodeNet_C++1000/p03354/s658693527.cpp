#include <bits/stdc++.h>
  
using namespace std;
  
template<class T> void ckmin(T &a, T b) { a = min(a, b); }
template<class T> void ckmax(T &a, T b) { a = max(a, b); }
  
#define pb push_back
#define mp make_pair
#define cotu cout
#define itn int
#define Red ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define F first
#define S second
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int i = 0; i < n; ++i)
#define repr(i,n) for(int i = n - 1; i >= 0; --i)
#define Rep(i, a, n) for(int i = (a); i <=(n); ++i)
#define repst(i, n) for(auto it = n.begin(); it != n.end(); ++it)
#define Repr(i, a, n) for(int i = (n); i >= (a); --i)
  
#define ordered_set tree<int , null_type,less<int >, rb_tree_tag,tree_order_statistics_node_update> 
  
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
  
const int inf = int(1e9);
const int mod = inf + 7;
const int N = 1e6 + 555; // TL MB
const double PI = acos(-1.0);
 
void mul(ll &x, ll y){
	x *= y;
	if(x >= mod) x %= mod;
}
 
void add(ll &x, ll y){
	x += y;
	if(x >= mod) x -= mod;
	if(x < 0) x += mod;
}
ll bp(ll a, ll n){
	ll r = 1;
	while(n){
		if(n & 1) mul(r, a);
		mul(a, a);
		n >>= 1;
	}
	return r;
}
int u[N], p[N];
vector<int> g[N];
map<int, int> a, b;
void dfs(int v){
	u[v] = 1;
	a[v] = 1;
	b[p[v]] = 1;
	for(int to : g[v]) if(!u[to]) dfs(to);	
}
void solve()
{
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) cin >> p[i + 1];
	for(int i = 0; i < m; ++i){
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
		g[y].pb(x);
	}
	for(int i = 1; i <= n; ++i) if(!u[i]) {
		dfs(i);
		vector<int> q;
		for(auto it : a){
			if(b.count(it.F)) {
				b.erase(it.F);
				p[it.F] = it.F;
			}
			else q.pb(it.F);
		}
		for(auto it : q){
			p[it] = (*b.begin()).F;
			b.erase(b.begin());
		}
		a.clear();
		b.clear();
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i) cnt += (i == p[i]);
	cout << cnt << '\n'; 
}


 // a b c a b c a b c a b c
 
int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    Red;
  	int T = 1;
  	//cin >> T;
  	for(int i = 1; i <= T; ++i){
  		solve();
  	}
  	return 0;

}