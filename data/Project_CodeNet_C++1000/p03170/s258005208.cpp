#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e2 + 10, K = 1e5 + 10;
ll a[N], dp[K];

int main()
{
	ll n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (ll kk = 0; kk < a[1]; kk++) dp[kk] = 2;
	for (ll kk = a[1]; kk <= k; kk++)
	{
		int f = 0;
		for (int i = 1; i <= n; i++)
		{
			if (a[i] > kk) break;
			if (dp[kk - a[i]] == 2)
			{
				f = 1;
				break;
			}
		}
		if (f) dp[kk] = 1;
		else dp[kk] = 2;
	}
	if (dp[k] == 1) cout << "First";
	else cout << "Second";
}
