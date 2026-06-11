#include <iostream>
#include <cmath>

int n;
int dp[3001][3001] = {};
int temp;

int main() {
	std::string s;
	std::string t;
	std::cin >> s >> t;
	for (int i = 1; i <= s.size(); i++) {
		for (int j = 1; j <= t.size(); j++) {
			if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else if (dp[i - 1][j] > dp[i][j - 1]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = dp[i][j - 1];
		}
	}
	int len = dp[s.size()][t.size()];
	std::string gyakuans = "";
	/*for (int i = 0; i <= s.size(); i++) {
		for (int j = 0; j <= t.size(); j++) {
			std::cout << dp[i][j] << " ";
		}
		std::cout << std::endl;
	}*/
	int i = s.size();
	int j = t.size();
	while (len > 0) {
		if (s[i-1]==t[j-1]) {
			gyakuans += s[i - 1];
			len--;
			i--;
			j--;
		}
		else if (dp[i][j] == dp[i][j - 1])j--;
		else i--;
	}
	//std::cout << gyakuans << std::endl;
	for (int i = gyakuans.size() - 1; i >= 0; i--) {
		std::cout << gyakuans[i];
	}
	std::cout << std::endl;
}
