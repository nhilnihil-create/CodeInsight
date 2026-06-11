#include <bits/stdc++.h>

#define N 200001

using namespace std;

const int MOD = 1e9 + 7;
int n;
int h[N];
long long a[N];
long long dp[N];
long long st[4 * N];

long long max(long long a, long long b)
{
	return (a < b) ? b : a;
}

void insert(int ind, long long val, int ss, int se, int si)
{
	if (ss > se)
		return;
	if (ss == se)
	{
		st[si] = val;
		return;
	}
	int mid = ss + (se - ss) / 2;
	if (ind <= mid)
		insert(ind, val, ss, mid, 2 * si + 1);
	else
		insert(ind, val, mid + 1, se, 2 * si + 2);
	st[si] = max(st[2 * si + 1], st[2 * si + 2]);
}

long long query(int qs, int qe, int ss, int se, int si)
{
	if (qs > se || qe < ss)
		return 0;
	if (qs <= ss && qe >= se)
		return st[si];
	int mid = (ss + se) / 2;
	return max(query(qs, qe, ss, mid, 2 * si + 1), query(qs, qe, mid + 1, se, 2 * si + 2));
}

long long solve()
{
	memset(dp, 0, sizeof(dp));
	memset(st, 0, sizeof(st));

	long long ans = 0;

	for (int i = 0; i < n; i++)
	{
		dp[h[i]] = a[i] + query(1, h[i] - 1, 1, n, 0);
		ans = max(ans, dp[h[i]]);
		insert(h[i], dp[h[i]], 1, n, 0);
	}
	return ans;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> h[i];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cout << solve() << endl;
	return 0;
}
