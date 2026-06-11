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

	int n, i, j, k;
	cin >> n;
	vector<long double> t(n + 1), v(n + 1), s(n + 1);
	for (i = 1; i <= n; i++) cin >> t[i];
	for (i = 1; i <= n; i++) cin >> v[i];

	for (i = 0; i <= n; i++) {
		if ((i == 0) || (i == n)) s[i] = 0;
		else s[i] = min(v[i], v[i + 1]);
	}

	for (i = 1; i <= n; i++) {
		s[i] = min(s[i], s[i - 1] + t[i]);
	}

	for (i = n - 1; i >= 0; i--) {
		s[i] = min(s[i], s[i + 1] + t[i + 1]);
	}

	long double ans, tt, ss, tv;
	ans = 0;
	for (i = 0; i < n; i++) {
		//tt = max(s[i + 1] - s[i], s[i] - s[i + 1]);
		tt = abs(s[i + 1] - s[i]);
		ans += tt * (s[i + 1] + s[i]) / 2.0;
		
		tt = t[i + 1] - tt;		// free time
		ss = max(s[i + 1], s[i]);

		if (ss + tt / 2.0 > v[i + 1]) {
			tv = v[i + 1] - ss;
			ans += (tt - tv * 2.0) * v[i + 1];
			ans += tv * (v[i + 1] + ss);
		}
		else {
			ans += tt * (ss + tt / 4);
		}
	}
	cout << setprecision(10) << fixed << ans << "\n";

	return 0;
}

