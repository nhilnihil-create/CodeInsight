#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
char str[N];
int dp[N][4];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		string s = "ABC";
		if (str[i] != '?') s = string(1, str[i]);
		for (auto& c : s)
		{
			dp[i][0] += dp[i - 1][0];
			if (dp[i][0] >= INF)
				dp[i][0] -= INF;
			for (int j = 1; j <= 3; j++)
			{
				dp[i][j] += dp[i - 1][j];
				if (dp[i][j] >= INF) dp[i][j] -= INF;
				if (c == j + 'A' - 1)
				{
					dp[i][j] += dp[i - 1][j - 1];
					if (dp[i][j] >= INF) dp[i][j] -= INF;
				}
			}
		}
	}
	cout << dp[n][3] << endl;
	return 0;
}
