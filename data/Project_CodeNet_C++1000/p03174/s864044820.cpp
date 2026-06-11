// unordered return continue break vector visited check flag bool while iterator temp true false ll_MAX ll_MIN insert pop push compare ll64_MAX ll64_MIN   replace stringstream string::npos  substr front 
#include<bits/stdc++.h>
using namespace std;
#ifdef AAYUSH
#include "/home/aayj/debug.cpp"
#else
#define debug(...) ;
#endif
#define ll  long long
const ll mod = 1e9 + 7 ;
const ll inf =
 1e9 + 5 ;
 //1e18L + 5;
void min_self(ll&a , ll b){a=min(a,b);}
void max_self(ll&a , ll b){a=max(a,b);}
void add_self(ll&a , ll b){a=(a+b);
	if(a>=mod)a-=mod;
}
#define all(x) x.begin(),x.end()
#define pb push_back
#define ff first
#define ss second
#define bg begin
#define ed end
#define lb lower_bound
#define ub upper_bound
#define cl clear
#define er erase
#define rev reverse
#define lg length
#define pii pair<ll,ll>
#define heap priority_queue
//#define (x)  get<0>(x) 
//#define (x)  get<1>(x)
//#define (x)  get<2>(x)
#define sz(a) (ll)((a).size())
#define forn(i, n) for (ll i = 0; i < ll(n); ++i)
#define fore(i, l, r) for (ll i = ll(l); i < ll(r); ++i)
#define YYY cout << "YES" << endl;
#define NNN cout << "NO" << endl;
const ll nax = 2e5+5   ;

signed main() {
ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
ll n; cin >> n;
ll can[n+1][n+1] = {0};
for(ll i = 0; i < n; i++){
	for(ll j = 0; j < n; j++){
		cin >> can[i+1][j+1];
	}
}
ll x = (1<<(n));

vector<vector<ll>> dp(n+1, vector<ll>(x));
// dp[0].fill(1);
fill(all(dp[0]),1);

for(ll mask = 0; mask < x-1; mask ++){
	ll a = __builtin_popcount(mask) + 1;
	for(ll b = 1; b<=n; b++){
		ll m2 = 1<<(b-1);
		if((!(mask&m2)) && can[a][b]){
			// assert(mask|m2 < x);
			// assert(a<=n);
			add_self(dp[a][mask|m2], dp[a-1][mask]);
		}
	}
}
cout << dp[n][x-1];
	
}
