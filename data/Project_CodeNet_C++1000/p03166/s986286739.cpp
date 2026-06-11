#include <iostream>
#include <vector>
#include <cmath>

int n, m;
int dp[100000] = {};
std::vector<int> path[100000];//gyaku

int dfs(int ima) {
	if (dp[ima] != 0) return dp[ima] + 1;
	else {
		for (int i = 0; i < path[ima].size(); i++) {
			int temp = dfs(path[ima][i]);
			if (dp[ima] < temp)dp[ima] = temp;
		}
	}
	return dp[ima] + 1;
}


int main() {
	std::cin >> n >> m;
	int temp, temp2;
	for (int i = 0; i < m; i++) {
		std::cin >> temp >> temp2;
		path[temp2 - 1].push_back(temp - 1);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] == 0) {
			temp = dfs(i);
			if (temp > ans)ans = temp;
		}
	}
	std::cout << ans-1 << std::endl;
}
