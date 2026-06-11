#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD (ll)(1e9+7)
#define INF (ll)(1e18)
#define debug(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false);\
debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> PII;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> VII;
int main()
{
	owo
   int n;
   cin>>n;
   vector<vector<bool>>adj(n,vector<bool>(n,0));
   for(int i=0;i<n;i++){
	   for(int j=0;j<n;j++){
	   bool x;
	   cin>>x;
	   adj[i][j] = x;
   }
}
   vector<ll>dp((1<<n)+2);
   dp[0] = 1;
   for(int mask = 0;mask<(1<<n)-1;mask++)
   {
	   for(int b=0;b<n;b++){
		   int a = __builtin_popcount(mask);
		   
		   if(adj[a][b] && !(mask&(1<<b))){
			   int nw_mask = mask^(1<<b);
			   dp[nw_mask]+=dp[mask];
			   dp[nw_mask]%=MOD;
		   }
	   }
   }
   cout<<dp[(1<<n)-1];
}