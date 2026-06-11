#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
#include<string>
using namespace std;
#define ll long long int
#define maxn 100005
#define mod 1e9+7

void _init() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}



int main() {
	_init();

	int n;
	cin >> n;

	vector<double> dp(n + 1);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		double phead;
		cin >> phead;
		for (int j = i; j >= 0; j--) {
			dp[j] = (j == 0 ? 0 : dp[j - 1] * phead) + dp[j] * (1 - phead);
		}
	}


	double ans = 0;
	for (int heads = 0; heads <= n; heads++) {
		int tails = n - heads;
		if (heads > tails) {
			ans += dp[heads];
		}
	}

	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}







