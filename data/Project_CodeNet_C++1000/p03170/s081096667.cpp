#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool winner(vector<ll>&moves, ll k, ll n)
{
	vector<bool>dp(k + 1, false);
	//true matlab pehla jitega
	//false matlab dusra jitega
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (moves[j] > i)
				continue;

			if (dp[i - moves[j]] == false)
			{
				dp[i] = true;
			}

		}
	}
	return dp[k];

}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n, k;
	cin >> n >> k;
	vector<ll>moves(n + 1);
	for (ll i = 1; i <= n; i++)
	{
		ll d;
		cin >> d;
		moves[i] = d;
	}
	if (winner(moves, k, n) == true)
	{
		cout << "First";
	}
	else
	{
		cout << "Second";
	}
	return 0;
}
