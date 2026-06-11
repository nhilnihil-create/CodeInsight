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
#define mod 1000000007
 
const long long INF=1e18+5;
 
typedef pair<int, int> pi;

int arr[1001][1001];
int dp[1001][1001]; 
 
void solve(){
	int n, m;
	cin>>n>>m;
	
	for(int i=1; i<=n; i++){
		string s;
		cin>>s;
		for(int j=1; j<=m; j++){
			arr[i][j]=s[j-1];
		}
	}
	
	dp[n][m]=1;
	
	for(int i=n-1; i>=1; i--){
		if(dp[i+1][m] && arr[i][m]!='#') dp[i][m]=1;
		else dp[i][m]=0;
	}
	
	for(int i=m-1; i>=1; i--){
		if(dp[n][i+1] && arr[n][i]!='#') dp[n][i]=1;
		else dp[n][i]=0;
	}
	
	for(int i=n-1; i>=1; i--){
		for(int j=m-1; j>=1; j--){
			if(arr[i][j]=='#') dp[i][j]=0;
			else dp[i][j]=(dp[i+1][j]+dp[i][j+1])%mod;
		}
	}
	cout<<dp[1][1]%mod<<endl;
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
