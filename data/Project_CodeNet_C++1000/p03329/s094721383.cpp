#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int>sn = { 6,36,216,1296,7776,46656 };
	reverse(sn.begin(), sn.end());
	vector<int>ni = {9,81,729,6561,59049};
	vector<int>dp(n+1,0);
	for (int i = 0; i <= n; i++) {
		ll ans = 0;
		ll x = i;
		for (int j = 0; j < sn.size(); j++) {
			ans += x / sn.at(j);
			x %= sn.at(j);
		}
		ans += x;
		dp.at(i) = ans;
	}
	for (int i = 0; i < ni.size(); i++) {
		int x = ni.at(i);
		for (int j = 0; j <= n; j++) {
			int res = 10000;
			for (int k = 0; k <= j/x; k++) {
				res = min(res, dp.at(j - x * k) + k);
			}
			dp.at(j) = min(dp.at(j), res);
		}
	}
	cout << dp.at(n) << endl;
}