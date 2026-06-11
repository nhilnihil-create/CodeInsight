#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<ll> x(N);
	vector<ll> y(N);
	vector<ll> z(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> x[i] >> y[i] >> z[i];
	}

	auto ans = 0ll;
	for (auto i = 0; i < 8; ++i)
	{
		vector<vector<ll>> dp(N + 1, vector<ll>(M + 1, LLONG_MIN));
		dp[0][0] = 0;
		for (auto j = 0; j < N; ++j)
		{
			for (auto k = 0; k <= M; ++k)
			{
				dp[j + 1][k] = dp[j][k];

				if (k < 1 || dp[j][k - 1] == LLONG_MIN)
				{
					continue;
				}

				auto sum = 0ll;
				if ((i & (1 << 0)) != 0)
				{
					sum += x[j];
				}
				else
				{
					sum -= x[j];
				}
				if ((i & (1 << 1)) != 0)
				{
					sum += y[j];
				}
				else
				{
					sum -= y[j];
				}
				if ((i & (1 << 2)) != 0)
				{
					sum += z[j];
				}
				else
				{
					sum -= z[j];
				}
				dp[j + 1][k] = max(dp[j + 1][k], dp[j][k - 1] + sum);
			}
		}
		ans = max(ans, dp[N][M]);
	}
	cout << ans << endl;

	return 0;
}