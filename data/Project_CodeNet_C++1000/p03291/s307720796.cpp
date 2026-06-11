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

long long int dp[100001][4];
const long long int MOD = 1e9 + 7;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;

	cin >> s;
	
	int n = s.length();
	
	dp[0][0] = 1;
	
	for (int i = 1; i <= n; i++)
	{
		if (s[i-1] == '?')
		{
			for (int j = 0; j <= 3; j++)
			{
				dp[i][j] = ((dp[i][j] % MOD) + ((3*dp[i - 1][j]) % MOD) % MOD);
				dp[i][j] %= MOD;
			}
			dp[i][1] = ((dp[i][1] % MOD) + (dp[i-1][0] % MOD)) % MOD;
			dp[i][1] %= MOD;
			dp[i][2] = ((dp[i][2] % MOD + (dp[i - 1][1]) % MOD) % MOD);
			dp[i][2] %= MOD;
			dp[i][3] = ((dp[i][3] % MOD) + (dp[i - 1][2] % MOD)) % MOD;
			dp[i][3] %= MOD;
		}
		else
		{
			for (int j = 0; j <= 3; j++)
			{
				dp[i][j] = ((dp[i][j] % MOD) + (dp[i - 1][j] % MOD) % MOD);
				dp[i][j] %= MOD;
			}
			if (s[i-1] == 'A')
			{
				dp[i][1] = ((dp[i][1] % MOD) + (dp[i-1][0] % MOD)) % MOD;
				dp[i][1] %= MOD;
			}
			else if (s[i-1] == 'B')
			{
				dp[i][2] = ((dp[i][2] % MOD) + (dp[i-1][1] % MOD)) % MOD;
				dp[i][2] %= MOD;
			}
			else
			{
				dp[i][3] = ((dp[i][3] % MOD) + (dp[i-1][2] % MOD)) % MOD;
				dp[i][3] %= MOD;
			}
		}
	}

	cout << dp[n][3] << '\n';

	return 0;
}
