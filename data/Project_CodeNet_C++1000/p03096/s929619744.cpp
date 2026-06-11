#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef vector <ll> vl;

const int N = 2e5 + 123, MOD = 1e9 + 7;
int n, c[N], a[N], m, dp[N], s[N];

void add(int & x, int y) {
	x += y;
	if (x >= MOD) {
		x -= MOD;
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] != c[i - 1]) {
			a[++m] = c[i];
		}
	}
	dp[0] = 1;
	for (int i = 1; i <= m; i++) {
		dp[i] = dp[i - 1];
		add(dp[i], s[a[i]]);
		add(s[a[i]], dp[i - 1]);
	}
	cout << dp[m];
}
