#include<bits/stdc++.h>
#define mod (long)(1e9 + 7)
using namespace std;

long dp[3000][3000];

long solve(int curr, int howManyLessLeft, string &s) {
	if(curr == s.size()) {
		return 1;
	}
	if(dp[curr][howManyLessLeft] != -1) return dp[curr][howManyLessLeft];
	long res = 0;
	if(s[curr] == '<') {
		int howManyHighLeft = (int)s.size() + 1 - (curr + 1 + howManyLessLeft);
		
		for(int i = 1; i <= howManyHighLeft; ++i) {
			res = (res + solve(curr + 1, howManyLessLeft + i - 1, s)) % mod;
		}
	}
	else {
		for(int i = 1; i <= howManyLessLeft; ++i) {
			res = (res + solve(curr + 1, i - 1, s)) % mod;
		}
	}
	return dp[curr][howManyLessLeft] = res;

}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	if(n == 1) {
		cout << 1;
		return 0;
	}
	string s;
	cin >> s;
	long res = 0;
	memset(dp, 0, sizeof dp);
	for(int i = 0; i <= n - 1; ++i) {
		dp[n - 1][i] = i + 1;
	}
	for(int i = n - 2; i >= 0; --i) {		// curr
		for(int j = 0; j <= n - 1; ++j) {	// lessCount
			if(s[i] == '<') {
				// cerr << "j:" <<j<<endl;
				int howManyHighLeft = n - (i + 1 + j);
				// cerr << i <<" " <<j << ":" << howManyHighLeft << endl;
				if(howManyHighLeft > 0) {
					dp[i][j] = (dp[i + 1][j + howManyHighLeft - 1] - 
						(j - 1 >= 0 ? dp[i + 1][j - 1] : 0) + mod) % mod;
				}
				// cerr<<"new j:" << j << endl;
			}
			else {
				if(j == 0) continue;
				dp[i][j] = dp[i + 1][j - 1];
			}
		}
		for(int j = 1; j <= n - 1; ++j) {
			dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
		}
	}
	cout << dp[0][n - 1];

	return 0;
}