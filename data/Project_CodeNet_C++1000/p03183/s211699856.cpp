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

	long long n, i, j, k, w, s, v, ans, x, MAXW = 20010;
	cin >> n;
	vector<tuple<long long, long long, long long>> plist(n);
	for (i = 0; i < n; i++) {
		cin >> w >> s >> v;
		plist[i] = { s + w, w, v };
	}
	sort(plist.begin(), plist.end());

	vector<long long> dp(MAXW, 0);
	for (i = 0; i < n; i++) {
		tie(s, w, v) = plist[i];

		for (j = s; j >= 0; j--) {
			if (j + w <= s) dp[j + w] = max(dp[j + w], dp[j] + v);
		}
	}

	ans = *max_element(dp.begin(), dp.end());
	cout << ans << "\n";


	return 0;
}

