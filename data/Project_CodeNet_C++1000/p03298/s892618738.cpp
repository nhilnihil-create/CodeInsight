#include <bits/stdc++.h>
using namespace std;

const int N = 20;

long long n, cnt, res;
string s;
string a, b;
long long dp[N][N];

void solve(int mask) {
	memset (dp, 0, sizeof dp);
	a = b = "";
	for (int i = 0; i < n; i++)
		if ((mask >> (n - i - 1)) & 1)
			a = s[i] + a;
		else
			b = s[i] + b;		
	dp[0][0] = 1;
	for (int i = 0; i <= b.size(); i++) {
		for (int j = 0; j <= a.size(); j++) {
			if (i < b.size() && s[s.size() - i - j - 1] == b[b.size() - i - 1])
				dp[i + 1][j] += dp[i][j];
			if (j < a.size() && s[s.size() - i - j - 1] == a[a.size() - j - 1])
				dp[i][j + 1] += dp[i][j];	
		}
	}
	res += dp[b.size()][a.size()];			
}

int main() {
	cin >> n;
	cin >> s;
	for (long long mask = 0; mask < (1 << n); mask++)
		solve(mask);
	cout << res;
}













