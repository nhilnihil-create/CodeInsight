#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

const ll INF = 100100100100;

int main() {
	int N;
	cin >> N;

	vector <ll> num;
	num.push_back(1);

	ll tmp = 6;
	while(tmp <= N){
		num.push_back(tmp);
		tmp *= 6;
	}

	tmp = 9;
	while(tmp <= N){
		num.push_back(tmp);
		tmp *= 9;
	}

	sort(num.begin(), num.end());

	vector <ll> dp(N+1, INF);
	dp[0] = 0;
	dp[1] = 1;
	for (ll ii = 2; ii <= N; ++ii){
		for (ll jj = 0; jj < num.size(); ++jj){
			ll idx = ii - num[jj];
			if (idx < 0) break;
			dp[ii] = min(dp[ii], dp[idx] + 1);
		}
	}

	cout << dp[N] << "\n";

	return 0;
}
