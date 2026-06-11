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
#include <numeric>
#include <math.h> 

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, i, j, k, ans, x, ct, nn, s, m;
	cin >> n;
	nn = 1 << n;
	
	vector<vector<long long>> plist(n + 1);		// by pop count
	vector<vector<int>> vlist(nn);
	ct = 0;
	plist[0].push_back(0);
	vlist[0].push_back(0);
	for (i = 0; i < n; i++) {
		x = 1 << i;
		for (j = n - 1; j >= 0; j--) {
			for (auto p : plist[j]) {
				plist[j + 1].push_back(p | x);
				for (auto pp : vlist[p]) {
					vlist[p | x].push_back(pp);
					vlist[p | x].push_back(pp | x);
					ct += 2;
				}
			}
		}
	}
	
	vector<vector<long long>> a(n, vector<long long>(n));
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) cin >> a[i][j];
	}

	vector<long long> dp(nn, -(1LL << 60));
	dp[0] = 0;
	for (i = 1; i <= n; i++) {
		for (auto p : plist[i]) {
			vector<int> id;
			for (j = 0; j < n; j++) {
				if ((1 << j) & p) id.push_back(j);
			}

			// value of no division
			s = 0;
			for (auto p1 : id) {
				for (auto p2 : id) s += a[p1][p2];
			}
			s /= 2;
			dp[p] = s;

			// divide and conquer
			for (auto pp : vlist[p]) {
				dp[p] = max(dp[p], dp[pp] + dp[p ^ pp]);
			}
		}
	}

	ans = dp[nn - 1];
	cout << ans << "\n";

	return 0;
}

