#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
vector<int> a(4, 0);
vector<vector<vector<double>>> dp;

double rec(int one, int two, int three)
{
	if (one == 0 && two == 0 && three == 0)
		return 0;
	if (one < 0 || two < 0 || three < 0)
		return 0;
	if (dp[one][two][three] != -1.0)
		return dp[one][two][three];
	dp[one][two][three] = 0;
	int rem = one + two + three;
	double val = N + one * rec(one - 1, two, three) + two * rec(one + 1, two - 1, three) + three * rec(one, two + 1, three - 1);
	val = val / rem;
	return dp[one][two][three] = val;
}

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		a[x]++;
	}
	dp.resize(N + 1);
	for (int i = 0; i <= N; i++)
	{
		dp[i].resize(N + 1, vector<double> (N + 1, -1.0));
	}
	double answer = rec(a[1], a[2], a[3]);
	cout << fixed << setprecision(12) << answer;

	return 0;
}