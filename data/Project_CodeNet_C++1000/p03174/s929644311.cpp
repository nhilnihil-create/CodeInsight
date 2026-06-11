#include <bits/stdc++.h>
using namespace std;
 
//#define kk
#define int long long
#define FOR(i, n) for(int i=1; i<=n; i++)
#define ff first
#define ss second
#define ll int
#define inf 1000000000
#define pb push_back
#define mod 1000000007
 
const long long INF=1e18+5;
typedef pair<int, int> pi;

int arr[21][21];
int dp[21][1<<21];

int bitmask(int i, int mask, int& n){
	if(i==n) return 1;
	
	if(dp[i][mask]!=-1) return dp[i][mask];
	
	int ans=0;
	for(int k=0; k<n; k++){
		if(arr[i][k] && (mask & (1<<k))) ans=ans%mod+bitmask(i+1, mask ^ (1<<k), n)%mod;
	}
	return dp[i][mask]=ans%mod;
}

void solve(){
	int n;
	cin>>n;
	
	FOR(i, n) FOR(j, n) cin>>arr[i-1][j-1];
	
	memset(dp, -1, sizeof dp);
	
	cout<<bitmask(0, (1<<n)-1, n)<<endl;
}
 
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cout<<fixed<<setprecision(10);
	
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
