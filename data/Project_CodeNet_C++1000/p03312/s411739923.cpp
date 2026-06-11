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

	long long n, i, j, k, ans, x, y, aa, bb;
	cin >> n;
	vector<long long> a(n + 1), s(n + 1, 0);
	vector<long long>::iterator it, it2;
	for (i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	ans = s[n];

	vector<long long> v(4);
	for (i = 2; i <= n - 2; i++) {
		x = s[i] / 2;
		it = lower_bound(s.begin() + 1, s.begin() + i - 1, x);
		it2 = it - 1;
		if (it == s.begin() + i) v[0] = *it2;
		else if (it2 == s.begin()) v[0] = *it;
		else {
			aa = *it; bb = *it2;
			if (abs(s[i] - aa - aa) <= abs(s[i] - bb - bb)) v[0] = aa;
			else v[0] = bb;
		}
		v[1] = s[i] - v[0];

		y = s[i] + (s[n] - s[i]) / 2;
		it = lower_bound(s.begin() + i + 1, s.begin() + n - 1, y);
		it2 = it - 1;
		if (it == s.begin() + n) v[2] = *it2 - s[i];
		else if (it2 == s.begin() + i) v[2] = *it - s[i];
		else {
			aa = *it; bb = *it2;
			if (abs(s[n] - aa - (aa - s[i])) <= abs(s[n] - bb - (bb - s[i]))) v[2] = aa - s[i];
			else v[2] = bb - s[i];
		}
		v[1] = s[i] - v[0];
		v[3] = s[n] - s[i] - v[2];
		sort(v.begin(), v.end());
		ans = min(ans, v[3] - v[0]);
	}

	cout << ans << "\n";

	return 0;
}

