#include<bits/stdc++.h> 
using namespace std;
typedef long long int ll;
#define MOD 1000000007
 
ll arr[105], dp[105][100005];

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
    ll i, j, n, k;
	cin >> n >> k;
	
    for(i=1; i<=n; i++) 
        cin >> arr[i];
	
    dp[0][0] = 1;
	for(i=1; i<=k; i++) 
        dp[0][i] = 0;
	
    for(i=1; i<=n; i++){
		for(j=1; j<=k; j++)
			dp[i-1][j] = (dp[i-1][j]+dp[i-1][j-1])%MOD;
			
		for(j=0; j<=k; j++){
			ll mn=j-arr[i]-1;
			dp[i][j] = dp[i-1][j];
			if(mn>=0) 
                dp[i][j] = (dp[i][j]-dp[i-1][mn]+MOD)%MOD;
		}
	}
	cout << dp[n][k];
	return 0;
}