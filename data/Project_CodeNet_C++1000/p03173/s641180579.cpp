#include<bits/stdc++.h>
using namespace std;
#define ll long long

//
ll dp[450][450];
ll ar[450];
ll pre[450];
//

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll n; cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> ar[i];
	for (ll i = 0; i < n; i++)
		pre[i + 1] = pre[i] + ar[i];

	for (ll len = 2; len <= n; len++)
	{
		ll st = 0;
		ll ed = len - 1;
		while (ed < n)
		{
			// cout << st << "," << ed << ": ";
			dp[st][ed] = 1e17;
			for (ll i = st; i < ed; i++)
			{
				// st to i
				// i + 1 to ed
				ll ans1 = dp[st][i];
				ll ans2 = dp[i + 1][ed];
				ll mix = pre[ed + 1] - pre[st];
				// cout << "[" << ans1 << "," << ans2 << "," << mix << "] ";
				dp[st][ed] = min(dp[st][ed], ans1 + ans2 + mix);
			}
			// cout << dp[st][ed] << "\n";
			st++; ed++;
		}
		// cout << "\n";
	}

	cout << dp[0][n - 1];
	return 0;
}