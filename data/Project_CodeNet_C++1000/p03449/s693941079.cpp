#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

int n, ar[4][102], dp[4][102];

signed main(){
	cin >> n;
	for (int i=1; i<=2; i++){
		for (int j=1; j<=n; j++) cin >> ar[i][j];
	}
	dp[1][1] = ar[1][1];
	for (int i=1; i<=2; i++){
		for (int j=1; j<=n; j++){
			dp[i][j] = max(dp[i-1][j], dp[i][j-1])+ar[i][j];
		}
	}
	cout << dp[2][n];
}

