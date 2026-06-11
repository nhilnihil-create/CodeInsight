#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <iomanip>
#include <string>
#include <queue>
#include <numeric>
#include <functional>
#include <array>
#include <map>
#include <set>

using namespace std;
using P = pair<int, int>;

long long MOD = 1000000007;
long long dp[100005][4];

int main() {
	string S;
	cin >> S;

	int size = S.size();

	for (int i = 0; i < 100005; ++i)for (int j = 0; j < 3; ++j)dp[i][j] = 0;
	dp[0][0] = 1;

	for (int i = 0; i < size;++i) {
		switch (S[i]) {
		case 'A':
			dp[i + 1][1] = (dp[i][1] + dp[i][0]) % MOD;
			dp[i + 1][2] = dp[i][2];
			dp[i + 1][3] = dp[i][3];
			dp[i + 1][0] = dp[i][0];
			break;
		case 'B':
			dp[i + 1][1] = dp[i][1];
			dp[i + 1][2] = (dp[i][2] + dp[i][1]) % MOD;
			dp[i + 1][3] = dp[i][3];
			dp[i + 1][0] = dp[i][0];
			break;
		case 'C':
			dp[i + 1][1] = dp[i][1];
			dp[i + 1][2] = dp[i][2];
			dp[i + 1][3] = (dp[i][3] + dp[i][2]) % MOD; 
			dp[i + 1][0] = dp[i][0];
			break;
		case '?': 
			dp[i + 1][1] = (dp[i][1] * 3 + dp[i][0]) % MOD;
			dp[i + 1][2] = (dp[i][2] * 3 + dp[i][1]) % MOD;
			dp[i + 1][3] = (dp[i][3] * 3 + dp[i][2]) % MOD;
			dp[i + 1][0] = (dp[i][0] * 3) % MOD;
			break;
		}
	}

	cout << dp[size][3] << endl;
}
