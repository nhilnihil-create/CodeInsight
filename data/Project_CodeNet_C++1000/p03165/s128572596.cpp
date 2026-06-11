#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
int p[3111];
int dp[3111][3111];
vector<char> ans;
int main() {
	string s1, s;
	cin >> s >> s1;
	s = " " + s;
	s1 = " " + s1;
	for (int i = 1; i < s.size(); i++) {
		for (int j = 1; j < s1.size(); j++) {
			if (s[i] == s1[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
	}
	int i = s.size()-1, j = s1.size()-1;
	while (i > 0 && j > 0) {
		if (dp[i][j] == dp[i - 1][j]) {
			i--;
		}
		else {
			if (dp[i][j] == dp[i][j-1]) {
				j--;
			}
			else {
				if (dp[i][j] = dp[i - 1][j - 1] + 1) {
					ans.push_back(s[i]);
					i--;
					j--;
				}
			}
		}
	}
	for (int i = ans.size() -1; i >=0 ; i--) {
		cout << ans[i];
	}
}