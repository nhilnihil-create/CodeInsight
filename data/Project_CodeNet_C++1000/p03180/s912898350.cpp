#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mxN = 17;
int N, a[mxN][mxN];
ll scores[1 << mxN], dp[1 << mxN];
vector<int> v;

void rec(int idx, int mask, int grp, ll score_now)
{
	if (idx == (int)v.size())
	{
		dp[mask] = max(dp[mask], score_now + scores[grp]);
		return;
	}
	rec(idx + 1, mask, grp, score_now);
	rec(idx + 1, mask ^ (1 << v[idx]), grp ^ (1 << v[idx]), score_now);
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> a[i][j];
	}
	for (int mask = 0; mask < (1 << N); mask++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				if ((mask & (1 << i)) && (mask & (1 << j)))
					scores[mask] += a[i][j];
			}
		}
	}
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int mask = 0; mask < (1 << N); mask++)
	{
		v.clear();
		for (int i = 0; i < N; i++)
		{
			if (!(mask & (1 << i)))
				v.push_back(i);
		}
		rec(0, mask, 0, dp[mask]);
	}
	cout << dp[(1 << N) - 1];

	return 0;
}