#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

const ll mdl = 1e9 + 7;



int main() {

	ll n, k;
	cin >> n >> k;

	ll ans[n + 1][k + 1];
	ll a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i <= k; i++) {
		ans[1][i] = (i <= a[0]) ? 1 : 0;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j == 0)
				ans[i][j] = ans[i - 1][j];
			else {
				ans[i][j] = (mdl + ans[i][j - 1] + ans[i - 1][j] - ((j - 1 - a[i - 1] >= 0) ? ans[i - 1][j - 1 - a[i - 1]] : 0 )) % mdl;
			}
		}
	}

	cout << (ans[n][k] % mdl) << endl;

	return 0;

}
