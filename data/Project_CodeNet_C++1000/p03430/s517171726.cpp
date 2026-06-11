#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define db double
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define mp make_pair
#define all(x) (x).begin(), (x).end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 303;
string s;
int n, k, dp[N][N][N];

int rec(int l, int r, int x) {
	if (x < 0) {
		return -N;
	}
	if (l > r) {
		return 0;
	}
	if (l == r) {
		return 1;
	}
	int & res = dp[l][r][x];
	if (res != -1) {
		return res;
	}
	res = 0;
	if (s[l] == s[r]) {
		res = rec(l + 1, r - 1, x) + 2;
	}
	res = max(res, rec(l + 1, r - 1, x - 1) + 2);
	res = max(res, rec(l + 1, r, x));
	res = max(res, rec(l, r - 1, x));
	return res;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif

	cin >> s >> k;
	n = s.size();
	memset(& dp, -1, sizeof(dp));
	cout << rec(0, n - 1, k);
}
