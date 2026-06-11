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
#define setp(x) fixed << setprecision(x)
#define o_set tree<int , null_type,less<int >, rb_tree_tag,tree_order_statistics_node_update> 
#define trav(it, v) for(auto &it : v)

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


int d(int x, int y)
{
	return abs(x - y);
}
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> pts(n);
	rep(i, n) cin >> pts[i];
	int res = inf;
	rep(i, n - k + 1){
		int f = pts[i], s = pts[i + k - 1];
		res = min(res, min(d(f, 0), d(s, 0)) + d(f, s));
	}
	cout << res;
}
int main()
{
    Red;
    // freopen("black.in", "r", stdin);
	// freopen("black.out", "w", stdout);
    int T = 1;
    // cin >> T;
    for(int i = 1; i <= T; ++i) {
    	// cout << "Case #" << i << ": ";
    	solve();
  	}
  	return 0;

}
