#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
	string s, t;
	cin >> s >> t;
	vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));
	for (int i = 0; i < (int)s.size(); i++) {
		for (int j = 0; j < (int)t.size(); j++) {
			if (s[i] == t[j]) chmax(dp[i + 1][j + 1], dp[i][j] + 1);
			chmax(dp[i + 1][j + 1], dp[i][j + 1]);
			chmax(dp[i + 1][j + 1], dp[i + 1][j]);
		}
	}
	string res;
	int i = s.size(), j = t.size();
	while (i > 0 && j > 0) {
		if (dp[i][j] == dp[i - 1][j]) {
			i--;
		}
		else if (dp[i][j] == dp[i][j - 1]) {
			j--;
		}
		else {
			res = s[i - 1] + res;
			i--;
			j--;
		}
	}
	cout << res << endl;
}