#include <bits/stdc++.h>
using namespace std;

//#define kk
//#define int long long
#define FOR(i, n) for(int i=1; i<=n; i++)
#define ff first
#define ss second
#define ll int
#define inf 1000000000
#define pb push_back

const long long INF=1e18+5;
 
typedef pair<int, int> pi;

vector<int> arr[100001];
int dp[100001];

int dfs(int v){
	if(dp[v]!=-1) return dp[v];
	
	int temp=0;
	for(int child: arr[v]){
		temp=max(temp, 1+dfs(child));
	}
	return dp[v]=temp;
}

void solve(){
	int n, m;
	cin>>n>>m;
	
	for(int i=1; i<=m; i++){
		int a, b;
		cin>>a>>b;
		arr[a].pb(b);
	}
	
	for(int i=1; i<=n; i++) dp[i]=-1;
	
	int ans=0;
	for(int i=1; i<=n; i++){
		int res=dfs(i);
		ans=max(ans, res);
	}
	cout<<ans<<endl;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
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
