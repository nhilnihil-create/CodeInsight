#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional> 
#include <iomanip>
#include <unordered_map>
#include <memory.h>
#include <cstring>
#include <fstream>

using namespace std;

long long int dp[100001][3];
const long long int MOD = 1e9 + 7;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;

	cin >> s;
	
	int n = s.length();
	long long int x = 1;

	if (s[0] == '?' || s[0]=='A')
	{
		dp[0][0] = 1;
		if (s[0] == '?')
		{
			x = (x * 3) % MOD;
		}
	}

	for (int i = 1; i < n; i++)
	{
		if (s[i] == '?')
		{
			for (int j = 0; j < 3; j++)
			{
				dp[i][j] = ((dp[i][j] % MOD) + ((3*dp[i - 1][j]) % MOD) % MOD);
				dp[i][j] %= MOD;
			}
			dp[i][0] = ((dp[i][0] % MOD) + (x % MOD)) % MOD;
			dp[i][0] %= MOD;
			dp[i][1] = ((dp[i][1] % MOD + (dp[i - 1][0]) % MOD) % MOD);
			dp[i][1] %= MOD;
			dp[i][2] = ((dp[i][2] % MOD) + (dp[i - 1][1] % MOD)) % MOD;
			dp[i][2] %= MOD;
			x = (x * 3) % MOD;
			x %= MOD;
		}
		else
		{
			for (int j = 0; j < 3; j++)
			{
				dp[i][j] = ((dp[i][j] % MOD) + (dp[i - 1][j] % MOD) % MOD);
				dp[i][j] %= MOD;
			}
			if (s[i] == 'A')
			{
				dp[i][0] = ((dp[i][0] % MOD) + (x % MOD)) % MOD;
				dp[i][0] %= MOD;
			}
			else if (s[i] == 'B')
			{
				dp[i][1] = ((dp[i][1] % MOD) + (dp[i-1][0] % MOD)) % MOD;
				dp[i][1] %= MOD;
			}
			else
			{
				dp[i][2] = ((dp[i][2] % MOD) + (dp[i-1][1] % MOD)) % MOD;
				dp[i][2] %= MOD;
			}
		}
	}

	cout << dp[n - 1][2] << '\n';

	return 0;
}
