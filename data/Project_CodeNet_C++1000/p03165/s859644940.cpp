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

int dp[3001][3001];

void solve(){
	string X, Y;
	cin>>X>>Y;
	
	int n=X.size(), m=Y.size();
	
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			if(i==0 || j==0) dp[i][j]=0;
			else if(X[i-1]==Y[j-1]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	int a=n, b=m;
	string s="";
	while(a>=1 && b>=1){
		if(X[a-1]==Y[b-1]) s.pb(X[a-1]), a--, b--;
		else{
			if(dp[a][b-1]>dp[a-1][b]) b--;
			else a--;
		}
	}
	
	reverse(s.begin(), s.end());
	cout<<s<<endl;
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
