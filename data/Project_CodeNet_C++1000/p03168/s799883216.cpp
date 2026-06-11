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

double h[3000];
double dp[3000][3000];

void solve(){
	int n;
	cin>>n;
	
	FOR(i, n) cin>>h[i];
	
	dp[0][0]=1;
	
	FOR(i, n) dp[i][0]=dp[i-1][0]*(1-h[i]);
	
	FOR(i, n)
		FOR(j, i)
			dp[i][j]=((dp[i-1][j-1]*h[i])+(dp[i-1][j]*(1-h[i])));
			
	double ans=0;
	
	for(int i=n/2+1; i<=n; i++) ans+=dp[n][i];
	
	cout<<ans<<endl;
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
