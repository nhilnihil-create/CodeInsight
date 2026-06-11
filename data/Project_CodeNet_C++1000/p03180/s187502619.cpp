#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
int n;
int a[16][16];
vector<ll> dp;
vector<ll> pre;

void rec(int i, vector<int> &notTaken, ll score, int mask, int group)
{
	if (i == notTaken.size())
	{
		dp[mask] = max(dp[mask], score + pre[group]);
		return;
	}
	rec(i + 1, notTaken, score, mask, group);
	rec(i + 1, notTaken, score, mask ^ (1 << notTaken[i]), group ^ (1 << notTaken[i]));
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	dp.resize(1 << n, LLONG_MIN);
	dp[0] = 0;
	pre.resize(1 << n, 0);
	for (int mask = 0; mask < (1 << n); mask++)
	{
		for (int i = 0; i < n; i++)
			if (mask & (1 << i))
				for (int j = i + 1; j < n; j++)
					if (mask & (1 << j))
						pre[mask] += a[i][j];
	}

	for (int mask = 0; mask < (1 << n); mask++)
	{
		vector<int> notTaken;
		for (int i = 0; i < n; i++)
			if (!(mask & (1 << i)))
				notTaken.push_back(i);
		rec(0, notTaken, dp[mask], mask, 0);
	}
	cout << dp[(1 << n) - 1] << endl;
	return 0;
}
