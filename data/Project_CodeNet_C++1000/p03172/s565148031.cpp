
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>


using namespace std;
typedef long long ll;

const int N = 200;
const int inf = 0x3f3f3f3f;
const int OO = 1e9 + 100;
const ll inf_long = 1e18;

ll mod = 1e9 + 7;

ll n, k, a[N];
ll dp[N][100009];

int main() {
	
	/*ios::sync_with_stdio(false);
	cin.tie(0);*/

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	dp[0][0] = 1;
	for (int i = 1; i <= k; ++i)
	{
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		ll *sum = new ll[k + 1];
		sum[0] = dp[i - 1][0];
		for (int j = 1; j <= k; ++j)
		{
			sum[j] = sum[j - 1] + dp[i - 1][j];
			sum[j] = sum[j] % mod;
		}
		for (int j = 0; j <= k; ++j)
		{
			ll finalSol = sum[j];
			int firstInvalid = a[i] + 1;
			if (j >= firstInvalid)
				finalSol = (finalSol - sum[j - firstInvalid] + mod) % mod;

			dp[i][j] = finalSol;
		}
	}
	cout << dp[n][k];


	return 0;
}
