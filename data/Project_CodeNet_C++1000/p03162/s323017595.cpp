#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<vector<int>> data(n + 10, vector<int>(3,0));
	rep(i, n) {
		cin >> data[i][0] >> data[i][1] >> data[i][2];
	}

	vector<vector<int>> dp(n + 10, vector<int>(3, 0));
	dp[0][0] = data[0][0];
	dp[0][1] = data[0][1];
	dp[0][2] = data[0][2];

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][1] + data[i][0], dp[i - 1][2] + data[i][0]);
		dp[i][1] = max(dp[i - 1][2] + data[i][1], dp[i - 1][0] + data[i][1]);
		dp[i][2] = max(dp[i - 1][0] + data[i][2], dp[i - 1][1] + data[i][2]);
	}
	
	cout << max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]) << endl;
	return 0;
}