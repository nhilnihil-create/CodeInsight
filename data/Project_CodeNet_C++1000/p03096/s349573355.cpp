#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 2e5 + 5, mod = 1e9 + 7;

int n, c[N], dp[N][2], prt[N];
vector <int> vec[N];

int sum(int a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
	if(a < 0)
		a += mod;
	return a;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		c[i]--;
	}
	n = unique(c, c + n) - c;
	dp[0][0] = 1;
	prt[c[0]] = 1;
	for (int i = 1; i < n; i++) {
		dp[i][0] = sum(dp[i - 1][0], dp[i - 1][1]);
		dp[i][1] = prt[c[i]];
		prt[c[i]] = sum(prt[c[i]], dp[i][0]);
	}
	cout << sum(dp[n - 1][0], dp[n - 1][1]) << "\n";
}
