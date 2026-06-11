#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, i, j, k, m, INF = 1000000, x;
	vector<int> vv = { INF, 2, 5, 5, 4, 5, 6, 3, 7, 6 }, v;
	vector<string> vs = { "", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	string ss;

	cin >> n >> m;
	v.assign(10, INF);
	while (m--) {
		cin >> x;
		v[x] = vv[x];
	}

	vector<string> dp(n + 1);
	dp[0] = "";
	for (i = 1; i <= n; i++) {
		dp[i] = "";
		for (j = 1; j <= 9; j++) {
			if ((v[j] != INF) && (i - v[j] >= 0) && ((i == v[j]) || (dp[i - v[j]] != ""))) {
				x = dp[i - v[j]].length() + 1;
				if (x > dp[i].length()) dp[i] = dp[i - v[j]] + vs[j]; 
				else if (x == dp[i].length()) {
					ss = dp[i - v[j]] + vs[j];;
					dp[i] = max(dp[i], ss);
				}
			}
		}
	}

	cout << dp[n] << "\n";

	return 0;
}