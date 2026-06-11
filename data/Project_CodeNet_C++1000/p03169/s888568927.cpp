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

	int n, i, j, k, x, hash, total;
	unordered_map<int, long double> dp;

	cin >> n;
	vector<int> ct(4, 0);
	for (i = 0; i < n; i++) {
		cin >> x;
		ct[x]++;
	}

	for (total = 0; total <= n; total++) {
		for (i = 0; i <= n; i++) {
			for (j = 0; j <= n; j++) {
				k = total - i - j;
				if (k < 0) continue;
				hash = i * 1000000 + j * 1000 + k;

				if (i + j + k == 0) dp[hash] = 0;
				else {
					long double ans = 0, r = (n - i - j - k) * 1.0 / n;
					if (i > 0) ans += i * 1.0 / n * (1 + dp[hash - 1000000 + 1000]);
					if (j > 0) ans += j * 1.0 / n * (1 + dp[hash - 1000 + 1]);
					if (k > 0) ans += k * 1.0 / n * (1 + dp[hash - 1]);

					ans = (r + ans) / (1 - r);
					dp[hash] = ans;
				}
			}
		}
	}

	x = ct[3] * 1000000 + ct[2] * 1000 + ct[1];
	long double ans = dp[x];
	cout << setprecision(10) << fixed << ans << "\n";

	return 0;
}


