#include<bits/stdc++.h>
#include <unistd.h>

#define pb push_back
#define ll long long
int mo =  1e9+7;
// int dp[1000][1000];
using namespace std;


int main(int argc, char const *argv[])
{
	// ios::sync_withss_stdio(false);
	// cin.tie(0);
	// cout.tie(0);

	int n, k;
	scanf("%d %d", &n, &k);

	int a[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}

	ll dp[n+1][k+1];

	memset(dp, 0, sizeof(dp));

	dp[0][0] = 1;

	std::vector<ll> sum(k+1);

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <=k ; ++j)
		{
			sum[j] = j == 0 ? dp[i-1][j] : sum[j-1]+dp[i-1][j];
		}

		for (int j = 0; j <= k; ++j)
		{
			int t = min(j, a[i-1]);
			if(t == j){
				dp[i][j] = sum[j] %mo;
			}
			else{
				dp[i][j] = (sum[j] - sum[j-a[i-1]-1]+mo)%mo;
			}
		}
	}

	printf("%lld\n", dp[n][k]);

}


