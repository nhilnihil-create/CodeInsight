#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define pb push_back

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;

int n, a[105][2], dp[105][2];

signed main(){
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i][0];
	for(int i = 1; i <= n; i++) cin >> a[i][1];
	for(int i = 1; i <= n; i++){
		dp[i][0] = dp[i - 1][0] + a[i][0];
		dp[i][1] = max(dp[i][0], dp[i - 1][1]) + a[i][1];
	}
	cout << dp[n][1];
}
