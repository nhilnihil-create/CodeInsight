#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mxN = 1010;
int N;

struct block
{
	int solid, weight, val;
};

block a[mxN];
ll dp[mxN][20005];

bool fun(const block& b1, const block& b2)
{
	return (b1.weight + b1.solid < b2.weight + b2.solid);
}

ll rec(int idx, int wt)
{
	if (idx == N)
	{
		return 0;
	}
	if (dp[idx][wt] != -1)
	{
		return dp[idx][wt];
	}
	dp[idx][wt] = rec(idx + 1, wt);
	if (a[idx].solid >= wt)
	{
		dp[idx][wt] = max(dp[idx][wt], a[idx].val + rec(idx + 1, wt + a[idx].weight));
	}
	return dp[idx][wt];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i].weight >> a[i].solid >> a[i].val;
	}
	sort(a, a + N, fun);
	memset(dp, -1, sizeof(dp));
	ll answer = rec(0, 0);
	cout << answer;

	return 0;
}
