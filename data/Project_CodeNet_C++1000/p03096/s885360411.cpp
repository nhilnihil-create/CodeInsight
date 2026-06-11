#pragma region
#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <iomanip>
#include <cstdint>
#include <cstdlib>

using namespace std;
typedef long long ll;
//#define rep(i, s, e) for (int(i) = (s); (i) < (e); ++(i))
#define rep(i, e) for (int(i) = 0; (i) < (e); ++(i))
#define rrep(i, s) for (int(i) = (s) - 1; (i) >= 0; --(i))
#define all(x) x.begin(),x.end()
#pragma endregion


int main()
{
	int n; cin >> n;
	vector<vector<int>> pos(200005);
	vector<ll> dp(n + 1);
	dp[0] = 1;
	int pre = 0;
	rep(i, n)
	{
		int a; cin >> a;
		dp[i + 1] = dp[i];
		if (pre != a && pos[a].size() != 0)
		{
			dp[i + 1] += dp[pos[a].back() + 1];
		}
		dp[i + 1] %= (ll)1e9 + 7;
		pos[a].push_back(i);
		pre = a;
	}
	cout << dp[n] << endl;
}