#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;

signed main(){
	int n;
	scanf("%d", &n);
	vector<vector<int> > a(n,vector<int> (n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) scanf("%d", &a[i][j]);
	}
	vector<ll> dp(1 << n, 0);
	dp[0] = 1;
	for(int bit = 1; bit < (1 << n); bit++){
		int num = __builtin_popcount(bit);
		for(int j = 0; j < n; j++){
			if(bit & (1 << j) && a[num - 1][j]){
				(dp[bit] += dp[bit - (1 << j)]) %= MOD;
			}
		}
	}
	cout << dp[(1 << n) - 1] << endl;
}