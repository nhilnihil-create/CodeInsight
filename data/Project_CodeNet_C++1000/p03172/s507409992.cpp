#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

const int N = 1e2 + 10, K = 1e5 + 10;
ll a[N], dp[N][K], ps[K];

int main()
{
	ll n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i <= a[1]; i++) dp[1][i] = 1;
	ps[1] = dp[1][0];
	for (int i = 2; i <= k + 1; i++)
	{
		ps[i] = ps[i - 1] + dp[1][i - 1];
		ps[i] %= mod;
	}
	for (int i = 2; i <= n; i++)
	{
		for (ll j = 0; j <= k; j++)
		{
			dp[i][j] = ps[j + 1] - ps[max(j - a[i], 0ll)];
			dp[i][j] %= mod;
		}
		ps[1] = dp[i][0];
		for (int j = 2; j <= k + 1; j++)
		{
			ps[j] = ps[j - 1] + dp[i][j - 1];
		}
	}
	cout << dp[n][k];
}
