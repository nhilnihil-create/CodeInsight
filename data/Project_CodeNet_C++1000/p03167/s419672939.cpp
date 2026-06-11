#include <bits/stdc++.h>
using namespace std;
long long n, m; char c;
int main (){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin >> n >> m;
long long dp[n+1][m+1];
memset(dp,0,sizeof(dp));
dp[1][1]=1;
for (int i=1; i<=n; i++){
	for (int j=1; j<=m; j++){
		cin >> c;
		if (c=='.' && (i!=1 || j!=1))
			dp[i][j]=(dp[i-1][j]+dp[i][j-1])%1000000007LL;
	}
} cout << dp[n][m];
return 0;
}
