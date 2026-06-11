#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_back
#define mp make_pair
#define endl "\n"
#define ff first
#define ss second
 
#ifndef ONLINE_JUDGE
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){cerr << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " << arg1 << "  ";
	__f(comma + 1, args...);}
#else
#define debug(...)
#endif
 
const int inf = 2e18;
const int ninf = -2e18-5;
const int mod = 1e9 + 7;
int n, k, cnt;

int arr[101];
int dp[101][100010];
int pre[101][100010];

signed main(){
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	#endif
 
	cin>>n>>k;
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<=k; j++){
			dp[i][j] = -1;
		}
	}

	for(int i=n-1; i>=0; --i){
		int now = 0;
		for(int j=0; j<=k; j++){
			if(i==n-1){
				if(j<=arr[i]) dp[i][j] = 1;
				else dp[i][j] = 0;
			}
			else{
				int l = min(arr[i], j);
				dp[i][j] = (pre[i+1][j] - pre[i+1][j-l] + dp[i+1][j-l] + mod)%mod;
			}
			now = (now + dp[i][j])%mod;
			pre[i][j] = now%mod;
		}
	}
	cout<<dp[0][k]%mod<<endl;
	return 0;
}