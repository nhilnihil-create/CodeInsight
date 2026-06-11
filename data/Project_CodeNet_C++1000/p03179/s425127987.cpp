#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7, mxN = 3010;
int N;
string S;
int dp[mxN][mxN];

int main()
{
	ios_base::sync_with_stdio(false);

	cin >> N >> S;
	dp[1][1] = 1;
	for (int i = 2; i <= N; i++)
	{
		ll pref[i];
		pref[0] = dp[i - 1][0];
		for (int j = 1; j < i; j++)
		{
			pref[j] = pref[j - 1] + dp[i - 1][j];
			if (pref[j] >= mod) pref[j] -= mod;
		}
		for (int j = 1; j <= i; j++)
		{
			int l, r;
			if (S[i - 2] == '>') l = 1, r = j - 1;
			else l = j, r = i - 1;
			dp[i][j] = pref[r] - pref[l - 1] + mod;
			if (dp[i][j] >= mod) dp[i][j] -= mod;
		}
	}
	ll answer = 0;
	for (int i = 1; i <= N; i++)
	{
		answer += dp[N][i];
		if (answer >= mod) answer -= mod;
	}
	cout << answer;

	return 0;
}