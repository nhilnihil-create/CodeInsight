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
#define ordered_set tree<int , null_type,less<int >, rb_tree_tag,tree_order_statistics_node_update> 
  
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
  
const int inf = int(1e9);
const int mod = inf + 7;
const int N = 3e5 + 555; // TL MB
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
int dp1[8008][8008], dp2[8008][8008];
vector<int> ud, rl;
void solve()
{
	string s;
	cin >> s;
	int cnt = 0, dr = 0, l = 0, sum1 = 0, sum2 = 0, le = 0, ri = 0, x, y, n;
	cin >> x >> y;
	n = sz(s);
	while(ri < n && s[ri] == 'F') ++ri;
	for(int j = ri + 1; j < n; ++j){
		if(s[j] == 'F') ++cnt;
		if((s[j] == 'T' || j == n - 1)) {
			if(!dr) ud.pb(cnt), sum1 += cnt;
			else rl.pb(cnt), sum2 += cnt;
			cnt = 0;
			dr ^= 1;
		}
	}
	// rep(i, sz(rl)) cout << rl[i] << " ";
	bool c1 = 0, c2 = 0;
	dp1[0][0] = 1;
	for(int i = 0; i < rl.size(); ++i){
		for(int j = 0; j <= 8000; ++j){
			if(dp1[i][j]){
				dp1[i + 1][j] = 1;
				dp1[i + 1][j + rl[i]] = 1;
			}
		}
	}
	dp2[0][0] = 1;
	for(int i = 0; i < ud.size(); ++i){
		for(int j = 0; j <= 8000; ++j){
			if(dp2[i][j]){
				dp2[i + 1][j] = 1;
				dp2[i + 1][j + ud[i]] = 1;
			}
		}
	}
	rep(i, sz(ud) + 1) rep(j, 8001) 
				if(dp2[i][j]){
					if(j + j - sum1 + le == y) c1 = 1;
					else if(-j - j + sum1 + le == y) c1 = 1;
			  }
	rep(i, sz(rl) + 1) rep(j, 8001) 
				if(dp1[i][j]){
					if(j + j - sum2 + ri == x) c2 = 1;
					else if(-j - j + sum2 + ri == x) c2 = 1;
				}
	if(c1 && c2) cout << "Yes";
	else cout << "No";

}
int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
    // Red;
  	int T = 1;
  	// cin >> T;
  	for(int i = 1; i <= T; ++i){
  		solve();
  	}
  	return 0;

}