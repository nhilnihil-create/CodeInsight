#include<bits/stdc++.h>
#define ll long long int
#define mp make_pair
#define pb push_back
#define ff first 
#define ss second
#define mod 1000000007
#define lim 100005
#define nfs_mw ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll dp[3001][3001] = {};

int main()
{
	ll ans = 0;
	int i,j,n;
	string s;
	cin>>n>>s;
	dp[n][1] = 1;
	for(i=n-1; i; i--){
		ll part = 0;
		if(s[i-1] == '>'){
			for(j=1; j<=n-i+1; j++){
				dp[i][j] = part;
				part = (part + dp[i+1][j])%mod;
			}
		}
		else{
			for(j=n-i+1; j; j--){
				dp[i][j] = part;
				part = (part + dp[i+1][j-1])%mod;
			}
		}
	}
	for(i=1; i<=n; i++) ans = (ans + dp[1][i])%mod;
	cout<<ans;
}