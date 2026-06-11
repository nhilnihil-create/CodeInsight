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

	long long n, k, i, j, ans, a, b, pp, p, s;
	cin >> n >> k;
	vector<long long> x(n), y(n);
	for (i = 0; i < n; i++) cin >> x[i] >> y[i];

	ans = 1LL << 62;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (x[i] <= x[j]) {
				vector<long long> p;
				for (a = 0; a < n; a++) {
					if ((x[a] >= x[i]) && (x[a] <= x[j])) p.push_back(y[a]);
				}
				sort(p.begin(), p.end());
				for (a = 0; a + k <= p.size(); a++) {
					s = (x[j] - x[i]) * (p[a + k - 1] - p[a]); 
					ans = min(ans, s);
				}

			}
		}
	}
	cout << ans << "\n";

	return 0;
}
