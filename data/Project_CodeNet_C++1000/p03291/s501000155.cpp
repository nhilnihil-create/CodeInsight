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

	string s;
	cin >> s;

	long long n = s.length(), i, j, k, ans, x, MOD = 1000000007;
	vector<long long> ll(n + 2), rr(n + 2), llct(n + 2), rrct(n + 2);

	llct[0] = 1;
	ll[0] = 0;
	for (i = 1; i <= n; i++) {
		if (s[i - 1] == 'A') {
			llct[i] = llct[i - 1];
			ll[i] = (ll[i - 1] + llct[i - 1]) % MOD;
		}
		else if (s[i - 1] == '?') {
			llct[i] = (llct[i - 1] * 3) % MOD;
			ll[i] = (ll[i - 1] * 3 + llct[i - 1]) % MOD;
		}
		else {
			llct[i] = llct[i - 1];
			ll[i] = ll[i - 1]; 
		}
	}

	rrct[n + 1] = 1;
	rr[n + 1] = 0;
	for (i = n; i >= 1; i--) {
		if (s[i - 1] == 'C') {
			rrct[i] = rrct[i + 1];
			rr[i] = (rr[i + 1] + rrct[i + 1]) % MOD;
		}
		else if (s[i - 1] == '?') {
			rrct[i] = (rrct[i + 1] * 3) % MOD;
			rr[i] = (rr[i + 1] * 3 + rrct[i + 1]) % MOD;
		}
		else {
			rrct[i] = rrct[i + 1];
			rr[i] = rr[i + 1];
		}
	}

	ans = 0;
	for (i = 2; i <= n - 1; i++) {
		if ((s[i - 1] == 'B') || (s[i - 1] == '?')) {
			x = (ll[i - 1] * rr[i + 1]) % MOD;
			ans = (ans + x) % MOD;
		}
	}

	cout << ans << "\n";

	return 0;
}
