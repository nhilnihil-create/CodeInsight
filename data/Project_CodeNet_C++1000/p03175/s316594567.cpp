#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long
#define ull unsigned long long
#define N 100005
#define mod 1000000007
//#define mod 1e18
#define boost ios_base::sync_with_stdio(false);cin.tie(0)
#define prec(n) fixed<<setprecision(n)

#define mii map<int,int>
#define mll map<ll,ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fi  first

#define se second
#define pb push_back
#define mp make_pair
#define pp pop_back
#define vii vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define all(c) c.begin(),c.end()
#define tr(it,c) for(it = c.begin() ; it!=c.end() ; it++)
int inf = INT_MAX ;
ll modulo(ll num,ll MOD=mod){ return ((num%MOD)+MOD)%MOD;} // for negative integer
ll power(ll b,ll e,ll MOD=mod){ll ans=1; while(e){if(e%2) ans=(ans*b)%MOD; b=(b*b)%MOD; e/=2;} return ans;}
ll inv(ll num,ll MOD=mod){ return power(modulo(num),MOD-2,MOD); }
ll gcd(ll a,ll b){ return ((b==0) ? a:gcd(b,a%b));}
int n;
vector<int> adj[N];
ll dp[N][2];

void dfs(int node,int p){
	ll ans1 = 1,ans2 = 1;
	for(int i:adj[node]){
		if(i!=p){
			dfs(i,node);
			ans1 = (ans1*dp[i][0])%mod;
			ans2 = (ans2*((dp[i][1] + dp[i][0])%mod))%mod;
		}
	}
	
	dp[node][0] = ans2;
	dp[node][1] = ans1;
}

int main(){
	boost;
	cin>>n;
	
	for(int i = 0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	dfs(1,-1);
	cout<<(dp[1][0]+dp[1][1])%mod;
	return 0;
}

