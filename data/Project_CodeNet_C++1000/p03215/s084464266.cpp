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

	long long n, i, j, k, ans, x, nn, ct;
	cin >> n >> k;
	nn = n * (n + 1) / 2;
	vector<long long> a(n + 1), s(n + 1, 0), v(nn);
	for (i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	ct = 0;
	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j++) {
			v[ct++] = s[j] - s[i - 1];
		}
	}

	ans = 0;
	for (i = 55; i >= 0; i--) {
		x = 1LL << i;
		ct = 0;
		for (auto p : v) {
			if (((p & ans) == ans) && ((p & x) == x)) ct++;
		}
		if (ct >= k) {
			ans += x;
		}
	}

	cout << ans << "\n";

		
	return 0;
}
