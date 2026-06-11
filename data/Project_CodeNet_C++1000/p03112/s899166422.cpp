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

ll get(ll x, ll y, ll z){
	return abs(x - y) + abs(y - z);
}
ll s[N], t[N], x[N];
void solve()
{
	int a, b, q;
	cin >> a >> b >> q;
	rep(i, a + a) s[i] = 1e18;
	rep(i, b + b) t[i] = 1e18;
	rep(i, a) cin >> s[i];
	rep(i, b) cin >> t[i];
	sort(s, s + a);
	sort(t, t + b);
	rep(i, q)
	{
		ll res = 1e12;
		cin >> x[i];
		int p1 = lower_bound(s, s + a, x[i]) - s;
		if(p1 != a){
			int p2 = lower_bound(t, t + b, s[p1]) - t;
			if(p2 != b){
				res = min(res, get(x[i], s[p1], t[p2]));
			}
			if(p2 != 0){
				res = min(res, get(x[i], s[p1], t[p2 - 1]));
			}
		}
		if(p1 != 0){
			int p2 = lower_bound(t, t + b, s[p1 - 1]) - t;
			if(p2 != b){
				res = min(res, get(x[i], s[p1 - 1], t[p2]));
			}
			if(p2 != 0){
				res = min(res, get(x[i], s[p1 - 1], t[p2 - 1]));
			}	
		}
		p1 = lower_bound(t, t + b, x[i]) - t;
		if(p1 != b){
			int p2 = lower_bound(s, s + a, t[p1]) - s;
			if(p2 != a){
				res = min(res, get(x[i], t[p1], s[p2]));
			}
			if(p2 != 0){
				res = min(res, get(x[i], t[p1], s[p2 - 1]));
			}
		}
		if(p1 != 0){
			int p2 = lower_bound(s, s + a, t[p1 - 1]) - s;
			if(p2 != a){
				res = min(res, get(x[i], t[p1 - 1], s[p2]));
			}
			if(p2 != 0){
				res = min(res, get(x[i], t[p1 - 1], s[p2 - 1]));
			}	
		}
		
		cout << res << '\n';
		
		
		
	}
}


 
 
int main()
{
    Red;
  	// int T; cin >> T; while(T--)
    solve();
    return 0;
}