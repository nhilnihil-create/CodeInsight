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

int arr[101];
int dp[100001];

int grundy(int n, int k){
	if(k<arr[1] || k==0) return 0;
	
	if(dp[k]!=-1) return dp[k];
	
	vector<int> v(n+1, 0);
	
	for(int i=1; i<=n; i++){
		if(k>=arr[i]) v[grundy(n, k-arr[i])]++;
	}
	
	int ans=0;
	for(int i=0; i<=n; i++){
		if(v[i]==0){
			ans=i;
			break;
		}
	}
	return dp[k]=ans;
}

void solve(){
	int n, k;
	cin>>n>>k;
	
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	
	memset(dp, -1, sizeof dp);
	if(grundy(n, k)==0) cout<<"Second"<<endl;
	else cout<<"First"<<endl;
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
