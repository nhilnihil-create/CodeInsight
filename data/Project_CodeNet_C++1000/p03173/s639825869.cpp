#include<bits/stdc++.h>
#include <unistd.h>

#define pb push_back
#define ll long long
#define inf 1e18

using namespace std;


int main(int argc, char const *argv[])
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);

	int n;
	scanf("%d", &n);
	vector<vector<ll>>dp(n, vector<ll>(n));
	vector<ll>pre(n, 0), a(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		dp[i][i] = 0;
		if(i == 0){
			pre[i] = a[i];
		}
		else{
			pre[i] = pre[i-1]+a[i];
		}
	}

	// printf("prefix array\n");

	// for(int i = 0; i<n; i++){
	// 	printf("for %d prefix sum is %lld \n",i,  pre[i]);
	// }
	for (int l = 2; l <= n; ++l)
	{
		for (int i = 0; i+l-1<n; ++i)
		{
			ll ss;
			int j = i+l-1;

			if(i == j){
				ss = a[i];
			}
			else if(i == 0){
				// printf("hrer %d\n", pre[j]);
				ss = pre[j];
			}
			else{
				// printf("subrecting\n");
				ss = pre[j] - pre[i-1];
			}
			dp[i][j] = inf;
			// printf("for %d -> %d , prefix sum is %lld\n",i, j, ss);
			for (int k = i; k < j; ++k)
			{
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + ss);
			}
		}
	}
	printf("%lld\n", dp[0][n-1]);

	
}


