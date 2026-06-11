#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int INF = 1e9;
int n;
int acts[100000][3];
int memo[100000][3];

int dp(int day = 0, int prev = -1)
{
	if (day == n)
		return 0;
	if (prev != -1 && memo[day][prev] > -1)
		return memo[day][prev];

	int res = -INF;
	for (int i = 0; i < 3; i++)
	{
		if (i == prev)
			continue;
		res = max(res, dp(day + 1, i) + acts[day][i]);
	}
	if (prev != -1)
		memo[day][prev] = res;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> acts[i][0] >> acts[i][1] >> acts[i][2];
	}
	memset(memo, -1, sizeof(memo));
	cout << dp();
}