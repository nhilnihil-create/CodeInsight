#include <bits/stdc++.h>
using namespace std;
 
//#define kk
#define int long long
#define FOR(a, b) for(int i=a; i<=b; i++)
#define REP(i, a, b) for(int i=a; i<=b; i++)
#define ff first
#define ss second
#define ll long long
#define inf 1000000000
#define pb push_back
#define mod 1000000007
 
const ll INF=1e18+5;
const int maxN=1e5+5;
typedef pair<int, int> pi;
 
vector<int> arr[maxN];
int dp[maxN][2];

void getWays(int v, int p){
	dp[v][0]=dp[v][1]=1;
	
	for(int child: arr[v]){
		if(child!=p){
			getWays(child, v);
			dp[v][0]=(dp[v][0]%mod*(dp[child][0]+dp[child][1])%mod)%mod;
			dp[v][1]=(dp[v][1]%mod*dp[child][0]%mod)%mod;
		}
	}
}

void solve(){
	int n;
	cin>>n;
	
	FOR(1, n-1){
		int a, b;
		cin>>a>>b;
		arr[a].pb(b);
		arr[b].pb(a);
	}
	
	getWays(1, -1);
	
	cout<<(dp[1][0]+dp[1][1])%mod<<endl;
}
 
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cout<<fixed<<setprecision(6);
	
	#ifdef kk
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	
	int T=1;
	//cin>>T;
	
	while(T--){		
		solve();
	}
}
