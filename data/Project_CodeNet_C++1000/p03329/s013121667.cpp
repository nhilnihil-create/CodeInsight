#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	clock_t begin = clock();
	int n;
	cin >> n;
	vector<ll>dp(n + 5, 1e9);
	vector<ll>choice;
	ll have = 1;
	while (n >= have) {
		have = have * 6;
		choice.pb(have);
	}
	have = 1;
	while (n >= have) {
		have = have * 9;
		choice.pb(have);
	}
	dp[0] = 0;
	for (int i = 0; i <= n; i++) {
		dp[i + 1] = min(dp[i + 1], 1 + dp[i]);
		for (auto k : choice) {
			if (i + k <= n) {
				dp[i + k] = min(dp[i + k], 1 + dp[i]);
			}
		}
	}
	cout << dp[n] << endl;
	clock_t end = clock();
	cerr << "Time run: " << (float)(end - begin) / CLOCKS_PER_SEC << " s" << endl;
}
