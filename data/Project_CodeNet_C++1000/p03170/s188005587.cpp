#include<bits/stdc++.h>

using namespace std;

#define int             long long


void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}





int f( vector<int>& a, int k) {

	int dp[k + 1];
	memset(dp, 0, sizeof dp);


	for (int i = 1; i <= k; i++) {


		for (auto x : a) {
			if (x > i)
				continue;
			if (dp[i - x] == 0)
				dp[i] = 1;
		}
	}
	return dp[k];
}
int32_t main() {
	c_p_c();

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i <= n; i++) {
		cin >> a[i];
	}
	int z = f(a, k);

	if (z == 1)
		cout << "First";
	else cout << "Second";

	return 0;
}
