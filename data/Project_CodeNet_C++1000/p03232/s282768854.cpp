#include <bits/stdc++.h>
 
using namespace std;
 
#define debug(a) cerr << #a << ": " << a << endl
 
typedef long long ll;
typedef pair<int, int> ii;
 
#define x first
#define y second
 
const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

int n, a[N];
int fact[N], suff_fact[N];
int dp[N], dp_pref[N];
int ans;

int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif
 
	cin >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}

	fact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = fact[i - 1] * 1LL * i % MOD;
	}

	suff_fact[0] = 1;
	for (int i = 1; i <= n; i++) {
		suff_fact[i] = suff_fact[i - 1] * 1LL * (n - (i - 1)) % MOD;
	}

	for (int i = 0; i < n; i++) {
		dp[i] = fact[i] * 1LL * suff_fact[n - (i + 1)] % MOD;
	}

	dp_pref[1] = dp[1];
	for (int i = 2; i < n; i++) {
		dp_pref[i] = (dp_pref[i - 1] + dp[i]) % MOD;
	}

	for (int i = 1; i <= n; i++) {
		ans = (ans + a[i] * 1LL * dp_pref[i - 1]) % MOD;
		ans = (ans + a[i] * 1LL * dp_pref[n - i]) % MOD;
		ans = (ans + a[i] * 1LL * fact[n]) % MOD;
	}

	cout << ans << endl;

	return 0;
}