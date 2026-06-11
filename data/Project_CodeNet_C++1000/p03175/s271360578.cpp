#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
typedef long long ll;
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pii pair < int , int >
#define pll pair < ll, ll >
#define mp make_pair
#define ff first
#define ld long double
#define ss second
#define vi vector < int >
#define vll vector < ll >
#define pb push_back
#define pf push_front
#define PI 3.1415926535897932384626
#define INF 0x3f3f3f3f
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)

const int mod = 1'000'000'007;

int mpow(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}
vector<vector<ll>> dp;
vector<vector<ll>> adj;

void dfs(int u, int pa)
{
	dp[u][0] = 1;
	dp[u][1] = 1;
	for(auto x: adj[u])
	{
		if(x == pa) continue;
		dfs(x, u);
		dp[u][0] = ((dp[u][0])*(dp[x][0]%mod + dp[x][1]%mod))%mod;
		dp[u][0]%=mod;
		dp[u][1] = ((dp[u][1])*dp[x][0]%mod)%mod; 
		dp[u][1]%=mod;
	}
	return;
}
	
int main()
{
		fastio;
		ll ttt = 1;
		//cin >> t;
		rep(tt,1,ttt+1)
		{
			ll n;
			cin >> n;
			adj.resize(n+1);
			dp.resize(n+1, vll(2));
			ll u, v;
			rep(i, 0, n-1)
			{
				cin >> u >> v;
				adj[u].pb(v);
				adj[v].pb(u);
			}
			dfs(1, -1);
			cout << (dp[1][0]+dp[1][1])%mod;
		}
		return 0;
	}
