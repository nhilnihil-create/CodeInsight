#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define N 22
#define mod 1000000007

ll dp[2097155];
int c[N][N], n;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
		}
	}

	ll s = 0;
	for (int i = 0; i < n; i++) {
		s += 1 << i;
	}

	dp[0] = 1; // if there are zero women left means all women are paired so this is one way

	for (ll j = 1; j <= s; j++) {
		int i = __builtin_popcountll(j);
		dp[j] = 0;
		ll tmp = j;
		i = n - i;

		for (int k = 0; k < n; k++) {
			int bit = tmp & 1;
			if (bit && c[i][k]) {
				dp[j] += dp[(j ^ (1 << k))];
				//cout << dp[j];
				dp[j] %= mod;
			}
			tmp = tmp >> 1;
		}
	}

	cout << dp[s];
}