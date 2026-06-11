#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define fi first
#define se second
#define pb push_back
 
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;
 
int n, a[2005];
bool dp[2005][200005];
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	dp[0][0] = 1;
	int lst = 0, tol = 0;
	for(int i = 1; i <= n; i++){
	    tol += a[i];
		for(int j = 0; j <= 100000; j++){
		    if(j < a[i]) dp[i][j] |= dp[i - 1][a[i] - j];
		    else dp[i][j] |= dp[i - 1][j - a[i]];
		    if(j + a[i] <= 100000) dp[i][j] |= dp[i - 1][j + a[i]];
		}
	}
	for(int i = 0; i <= 100000; i++){
		if(dp[n][i]){
			cout << (tol + i) / 2;
			return 0;
		}
	}
}