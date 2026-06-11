#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int INF = 1e9;
int n;
int heights[100000];
int memo[100000];

int dp(int i)
{
	if (i < 0)
		return INF;
	if (i == 0)
		return 0;
	if (memo[i] > -1)
		return memo[i];

	int cur = heights[i];
	int res1 = dp(i - 1) + abs(cur - heights[i - 1]);
	int res2 = dp(i - 2) + abs(cur - heights[i - 2]);
	int res = min(res1, res2);
	memo[i] = res;
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> heights[i];
	}
	memset(memo, -1, sizeof(memo));
	cout << dp(n - 1);
}