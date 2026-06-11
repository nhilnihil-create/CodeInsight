#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const ll inf = 2e18;

ll solve(int l, int r, vector<ll>& a, vector<vector<ll>>& dp) {
	if (l == r)return 0;
	ll &res = dp[l][r];
	if (res != -1)return res;
	res = inf;
	ll sum = 0, ans;
	for (int i = l; i <= r; i++)sum += a[i];

	for (int i = l; i < r; i++) {
		ans = solve(l, i, a, dp) + solve(i + 1, r, a, dp) + sum;
		res = min(res, ans);
	}

	return res;
}

int main() {


	int n;
	cin >> n;
	vector<vector<ll>> dp(n, vector<ll>(n, -1));
	vector<ll>a(n);
	for (auto & c : a)cin >> c;

	ll ans = solve(0, n - 1, a, dp);

	cout << ans << endl;


	return 0;
}