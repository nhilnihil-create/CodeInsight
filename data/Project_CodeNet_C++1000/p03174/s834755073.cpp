#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main(){
	int n; cin >> n;
	bool v[n][n];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> v[i][j];
		}
	}
	vector<int> dp(1<<n); dp[0] = 1;
	// mask means for the women match...
	for(int mask = 0; mask < (1<<n) - 1; ++mask){
		int a = __builtin_popcount(mask); // this will calculate no. of men match with women and we assume that first 'a' men match
		if(!dp[mask]) continue; 
		// now we check which women don't match till now....
		for(int b = 0; b < n; b++){
			if(v[a][b] && !(mask & (1<<b))){
				int x = mask^(1<<b);
				dp[x] += dp[mask]; dp[x] %= mod;
			}
		}
	}
	cout << dp[(1<<n) - 1];
}