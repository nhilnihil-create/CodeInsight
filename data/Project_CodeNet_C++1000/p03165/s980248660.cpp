#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mxN = 1e5+7;

int main() {
	string s, t;
	cin >> s >> t;
	int a = s.length(), b = t.length();
	vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));
	
	for(int i = 1; i <= a; i++) {
		for(int j = 1; j <= b; j++) {
			if(s[i-1] == t[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	
	int len = dp[a][b];
	string ans(len, ' ');
	int i = a, j = b;
	while(i > 0 && j > 0) {
		if(s[i-1] == t[j-1]) {
			ans[len - 1] = s[i-1];
			i--; j--; len--;
		}
		else if(dp[i-1][j] > dp[i][j-1]) {
			i--;
		}
		else {
			j--;
		}
	}
	cout << ans << "\n";
}
