#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define ip pair<int,int>
#define MAX 3005
// const ll INF = 1000000000000000000;
const ll MOD = 1000000007;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll n;
	cin>>n;
	string s;
	cin>>s;
	ll dp[n+1][n+1];
	memset(dp,0,sizeof(dp));
	dp[1][1] = 1;
	for(int i=2;i<=n;i++){
		if(s[i-2] == '<'){
			ll cur = 0;
			for(int j=2;j<=i;j++){
				cur += dp[i-1][j-1];
				if(cur >= MOD)
					cur -= MOD;
				dp[i][j] = cur;
			}
		}
		else{
			ll cur = 0;
			for(int j=i-1;j>=1;j--){
				cur += dp[i-1][j];
				if(cur >= MOD)
					cur -= MOD;
				dp[i][j] = cur;
			}
		}
	}

	ll ans = 0;
	for(int i=1;i<=n;i++){
		ans += dp[n][i];
		if(ans >= MOD)
			ans -= MOD;
	}

	cout<<ans<<endl;
}
