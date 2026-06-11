#include<bits/stdc++.h>
using namespace std;

long long dp[1001][1001];
const long long mod = 1e9 + 7;
int main() {
	int h, w;
	cin >> h >> w;
	vector<string> path;
	string s;
	for (int i = 0; i < h; i++) {
		cin >> s;
		path.push_back(s);
	}

	for (int i = 0; i <= h - 1; i++) {
		for (int j = 0; j <= w - 1; j++) {
			if (i == 0 && j == 0) {
				dp[i][j] = 1;
			}
			if (path[i][j] != '#') {
				dp[i][j] += (i - 1 >= 0) ? dp[i - 1][j] : 0;
				dp[i][j] %= mod;
				dp[i][j] += (j - 1 >= 0) ? dp[i][j - 1] : 0;
				dp[i][j] %= mod;
			}
		}
	}

	cout << dp[h - 1][w - 1] << endl;
	return 0;
}