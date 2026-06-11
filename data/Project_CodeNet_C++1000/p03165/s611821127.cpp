#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define times(t) int t; cin >> t; while(t--)
#define mod 1000000007

void solve() {
	string s, t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	int dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(s[i-1] == t[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	string temp;
	int i = n, j = m;
	while(i>0 && j>0) {
		if(s[i-1] == t[j-1]) {
			temp.push_back(s[i-1]);
			i--; j--;
			continue;
		}
		if(dp[i-1][j] > dp[i][j-1]) i--;
		else j--;
	}
	reverse(temp.begin(), temp.end());
	cout << temp << endl;
	return;
}

int main() {
	IOS;
	// #ifndef ONLINE_JUDGE
	// freopen("C:/Gen code/CompProg/input.txt", "r", stdin);
	// freopen("C:/Gen code/CompProg/output.txt", "w", stdout);
	// #endif
	solve();
	return 0;
}