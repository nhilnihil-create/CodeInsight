#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define watch(x) cout<<(#x)<<"="<<(x)<<'\n'
#define mset(d,val) memset(d,val,sizeof(d))
#define setp(x) cout<<fixed<<setprecision(x)
#define forn(i,a,b) for(int i=(a);i<(b);i++)
#define fore(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define F first
#define S second
#define pqueue priority_queue
#define fbo find_by_order
#define ook order_of_key
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void amin(ll &a, ll b){ a=min(a,b); }
void amax(ll &a, ll b){ a=max(a,b); }
void YES(){cout<<"YES\n";} void NO(){cout<<"NO\n";}
void SD(int t=0){ cout<<"PASSED "<<t<<endl; }
const ll INF = ll(1e18);
const int MOD = 1e9+7;

ll add(ll a, ll b)
{
	a+=b; a%=MOD;
	if(a<0) a+=MOD;
	return a;
}
ll mult(ll a, ll b)
{
	if(a>MOD) a%=MOD;
	if(b>MOD) b%=MOD;
	ll ans=(a*b)%MOD;
	if(ans<0) ans+=MOD;
	return ans;
}
ll pw(ll a, ll b)
{
	ll r=1;
	while(b){
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}
ll inverse(ll a)
{
	return pw(a,MOD-2);
}

const bool DEBUG = 0;
const int MAXN = 100005;

int n;
vi adj[MAXN];
ll dp[MAXN][2];

void dfs(int u, int p)
{
	dp[u][0]=dp[u][1]=1;
	for(int v: adj[u])
	{
		if(v==p) continue;
		dfs(v,u);
		dp[u][0]=mult(dp[u][0], add(dp[v][0], dp[v][1]));
		dp[u][1]=mult(dp[u][1], dp[v][0]);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin>>n;
	forn(i,0,n-1)
	{
		int u,v; cin>>u>>v; u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs(0,-1);
	
	cout<<add(dp[0][0], dp[0][1])<<'\n';
	
	return 0;
}
